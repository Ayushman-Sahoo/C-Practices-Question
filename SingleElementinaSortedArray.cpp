/*540. Single Element in a Sorted Array
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which
appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.
Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10

Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/

#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // Make mid even
        if (mid % 2 == 1) {
            mid--;
        }

        // Pair is correct, go right
        if (nums[mid] == nums[mid + 1]) {
            left = mid + 2;
        }
        // Pair is broken, go left
        else {
            right = mid;
        }
    }

    return nums[left];
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << singleNonDuplicate(nums) << endl;

    return 0;
}