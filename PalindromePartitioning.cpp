/*131. Palindrome Partitioning
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome 
partitioning of s.
Example 1:
Input: s = "aab" Output: [["a","a","b"],["aa","b"]] 
Example 2:
Input: s = "a" Output: [["a"]] 
Constraints:
- 1 <= s.length <= 16
- s contains only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> current;

    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    void backtrack(string &s, int start) {
        if (start == s.length()) {
            ans.push_back(current);
            return;
        }

        for (int end = start; end < s.length(); end++) {

            if (isPalindrome(s, start, end)) {

                current.push_back(
                    s.substr(start, end - start + 1)
                );

                backtrack(s, end + 1);

                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return ans;
    }
};

int main() {
    string s;
    cin >> s;

    Solution obj;
    vector<vector<string>> result = obj.partition(s);

    for (auto &partition : result) {
        cout << "[";
        
        for (int i = 0; i < partition.size(); i++) {
            cout << "\"" << partition[i] << "\"";

            if (i != partition.size() - 1)
                cout << ",";
        }

        cout << "]" << endl;
    }

    return 0;
}