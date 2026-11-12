/*4. Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
*/

#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    // Binary search on smaller array
    if (nums1.size() > nums2.size()) {
        swap(nums1, nums2);
    }

    int m = nums1.size();
    int n = nums2.size();

    int low = 0;
    int high = m;

    while (low <= high) {

        int cut1 = (low + high) / 2;
        int cut2 = (m + n + 1) / 2 - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];

        int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];

        // Correct partition
        if (left1 <= right2 && left2 <= right1) {

            // Even number of elements
            if ((m + n) % 2 == 0) {
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }

            // Odd number of elements
            else {
                return max(left1, left2);
            }
        }

        // Move partition to the left
        if (left1 > right2) {
            high = cut1 - 1;
        }

        // Move partition to the right
        else {
            low = cut1 + 1;
        }
    }

    return 0.0;
}

int main() {

    int m, n;

    cin >> m;

    vector<int> nums1(m);

    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    cin >> n;

    vector<int> nums2(n);

    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    double answer = findMedianSortedArrays(nums1, nums2);

    cout << fixed << setprecision(5) << answer << endl;

    return 0;
}