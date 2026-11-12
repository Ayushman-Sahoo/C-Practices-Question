/*493. Reverse Pairs
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1

Constraints:

1 <= nums.length <= 5 * 10^4
-2^31 <= nums[i] <= 2^31 - 1
*/

#include <iostream>
#include <vector>
using namespace std;

long long mergeSort(vector<int>& nums, int low, int high) {
    
    if (low >= high)
        return 0;
    
    int mid = low + (high - low) / 2;
    
    long long count = 0;
    
    // Count reverse pairs in left and right halves
    count += mergeSort(nums, low, mid);
    count += mergeSort(nums, mid + 1, high);
    
    // Count cross reverse pairs
    int j = mid + 1;
    
    for (int i = low; i <= mid; i++) {
        
        while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
            j++;
        }
        
        count += j - (mid + 1);
    }
    
    // Merge two sorted halves
    vector<int> temp;
    
    int i = low;
    j = mid + 1;
    
    while (i <= mid && j <= high) {
        
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        } 
        else {
            temp.push_back(nums[j]);
            j++;
        }
    }
    
    while (i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }
    
    while (j <= high) {
        temp.push_back(nums[j]);
        j++;
    }
    
    // Copy back
    for (int k = low; k <= high; k++) {
        nums[k] = temp[k - low];
    }
    
    return count;
}

int main() {
    
    int n;
    
    cout << "Enter number of elements: ";
    cin >> n;
    
    vector<int> nums(n);
    
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    long long result = mergeSort(nums, 0, n - 1);
    
    cout << "Number of Reverse Pairs = " << result << endl;
    
    return 0;
}