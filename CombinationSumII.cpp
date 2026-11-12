/*40. Combination Sum II
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where 
the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
vector<int> temp;

void solve(vector<int>& candidates, int target, int start) {
    if (target == 0) {
        ans.push_back(temp);
        return;
    }

    for (int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i - 1])
            continue;

        if (candidates[i] > target)
            break;

        temp.push_back(candidates[i]);
        solve(candidates, target - candidates[i], i + 1);
        temp.pop_back();
    }
}

int main() {
    int n, target;
    cin >> n;

    vector<int> candidates(n);
    for (int i = 0; i < n; i++)
        cin >> candidates[i];

    cin >> target;

    sort(candidates.begin(), candidates.end());
    solve(candidates, target, 0);

    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j];
            if (j + 1 < ans[i].size()) cout << ",";
        }
        cout << "]";
        if (i + 1 < ans.size()) cout << ",";
    }
    cout << "]\n";

    return 0;
}
