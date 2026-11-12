/*39. Combination Sum
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates 
where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at 
least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for 
the given input.

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []

Constraints:
1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40
*/

#include <bits/stdc++.h>
using namespace std;

void backtrack(int index, int target, vector<int>& candidates,
               vector<int>& current, vector<vector<int>>& result) {

    // Target achieved
    if (target == 0) {
        result.push_back(current);
        return;
    }

    for (int i = index; i < candidates.size(); i++) {

        // Since array is sorted, no further candidate can work
        if (candidates[i] > target)
            break;

        // Choose the current candidate
        current.push_back(candidates[i]);

        // Use i again because the same number can be reused
        backtrack(i, target - candidates[i],
                  candidates, current, result);

        // Remove the chosen number
        current.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    vector<vector<int>> result;
    vector<int> current;

    sort(candidates.begin(), candidates.end());

    backtrack(0, target, candidates, current, result);

    return result;
}

int main() {

    int n, target;

    cout << "Enter number of candidates: ";
    cin >> n;

    vector<int> candidates(n);

    cout << "Enter candidates: ";
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }

    cout << "Enter target: ";
    cin >> target;

    vector<vector<int>> result = combinationSum(candidates, target);

    cout << "Combinations:\n";

    cout << "[";

    for (int i = 0; i < result.size(); i++) {

        cout << "[";

        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];

            if (j != result[i].size() - 1)
                cout << ",";
        }

        cout << "]";

        if (i != result.size() - 1)
            cout << ",";
    }

    cout << "]" << endl;

    return 0;
}