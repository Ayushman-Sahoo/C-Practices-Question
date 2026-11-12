/* 18. 4Sum
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
Constraints:

1 <= nums.length <= 200
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
vector<vector<int>> fourSum(vector<int>& nums, int target) {
vector<vector<int>> ans;
int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; i++) {

        // Skip duplicate values for i
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n - 2; j++) {

            // Skip duplicate values for j
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1;
            int right = n - 1;

            while (left < right) {

                long long sum = (long long)nums[i]
                              + nums[j]
                              + nums[left]
                              + nums[right];

                if (sum == target) {

                    ans.push_back({
                        nums[i],
                        nums[j],
                        nums[left],
                        nums[right]
                    });

                    // Skip duplicate left values
                    while (left < right &&
                           nums[left] == nums[left + 1])
                        left++;

                    // Skip duplicate right values
                    while (left < right &&
                           nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
    }

    return ans;
}
};
int main() {
vector<int> nums = {1, 0, -1, 0, -2, 2};
int target = 0;
Solution obj;
vector<vector<int>> result = obj.fourSum(nums, target);
cout << "Quadruplets are:" << endl;
for (auto quadruplet : result) {
    cout << "[ ";
    for (int x : quadruplet) {
        cout << x << " ";
    }
    cout << "]" << endl;
}
return 0;
}