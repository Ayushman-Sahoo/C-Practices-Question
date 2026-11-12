/*79. Word Search
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically 
neighboring. The same letter cell may not be used more than once.

Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool solve(vector<vector<char>>& board, string& word,
           int i, int j, int k) {

    if (k == word.size())
        return true;

    if (i < 0 || j < 0 ||
        i >= board.size() || j >= board[0].size() ||
        board[i][j] != word[k])
        return false;

    char ch = board[i][j];
    board[i][j] = '#';

    bool found =
        solve(board, word, i + 1, j, k + 1) ||
        solve(board, word, i - 1, j, k + 1) ||
        solve(board, word, i, j + 1, k + 1) ||
        solve(board, word, i, j - 1, k + 1);

    board[i][j] = ch;

    return found;
}

bool exist(vector<vector<char>>& board, string word) {

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {

            if (solve(board, word, i, j, 0))
                return true;
        }
    }

    return false;
}

int main() {

    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string word = "ABCCED";

    if (exist(board, word))
        cout << "true";
    else
        cout << "false";

    return 0;
}