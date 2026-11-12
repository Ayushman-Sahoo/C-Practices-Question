/*MERGE SORT: COUNTING INVERSIONS

In an array, arr, the elements at indices i and j (where i < j) form an inversion if arr[i] > arr[j]. In other words, inverted 
elements arr[i] and arr[j] are considered to be "out of order". To correct an inversion, we can swap adjacent elements.

Example:

arr = [2, 4, 1]

To sort the array, we must perform the following two swaps to correct the inversions:

[2, 4, 1]
[2, 1, 4]
[1, 2, 4]

The sort has two inversions: (4, 1) and (2, 1).

Given an array arr, return the number of inversions to sort the array.

FUNCTION DESCRIPTION

Complete the function countInversions in the editor below.

countInversions has the following parameter:

    int arr[n]: an array of integers to sort

Returns:

    long: the number of inversions

INPUT FORMAT

The first line contains an integer, d, the number of datasets.

Each of the next d pairs of lines is as follows:

1. The first line contains an integer, n, the number of elements in arr.
2. The second line contains n space-separated integers, arr[i].

CONSTRAINTS

1 <= d <= 15
1 <= n <= 10^5
1 <= arr[i] <= 10^7

SAMPLE INPUT

2
5
1 1 1 2 2
5
2 1 3 1 2

SAMPLE OUTPUT

0
4
EXPLANATION

We sort the following d = 2 datasets:

1. arr = [1, 1, 1, 2, 2]

   The array is already sorted, so there are no inversions to correct.

2. arr = [2, 1, 3, 1, 2]

   We need 4 swaps to sort the array.

   [2, 1, 3, 1, 2]
   [1, 2, 3, 1, 2]
   [1, 2, 1, 3, 2]
   [1, 1, 2, 3, 2]
   [1, 1, 2, 2, 3]

Therefore, the answer is 4.
*/

#include <bits/stdc++.h>
using namespace std;

// Merge two sorted halves and count inversions
long long mergeAndCount(vector<int>& arr, vector<int>& temp,
                        int left, int mid, int right) {

    int i = left;       // Left half
    int j = mid + 1;    // Right half
    int k = left;

    long long inversions = 0;

    while (i <= mid && j <= right) {

        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];

            // All remaining elements in the left half
            // are greater than arr[j]
            inversions += (mid - i + 1);
        }
    }

    // Copy remaining elements from left half
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from right half
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy sorted elements back to arr
    for (int p = left; p <= right; p++) {
        arr[p] = temp[p];
    }

    return inversions;
}

// Merge sort and count inversions
long long mergeSortAndCount(vector<int>& arr, vector<int>& temp,
                            int left, int right) {

    long long inversions = 0;

    if (left < right) {

        int mid = left + (right - left) / 2;

        // Count inversions in left half
        inversions += mergeSortAndCount(arr, temp, left, mid);

        // Count inversions in right half
        inversions += mergeSortAndCount(arr, temp, mid + 1, right);

        // Count inversions between both halves
        inversions += mergeAndCount(arr, temp, left, mid, right);
    }

    return inversions;
}

// Main function
long long countInversions(vector<int> arr) {

    if (arr.size() <= 1) {
        return 0;
    }

    vector<int> temp(arr.size());

    return mergeSortAndCount(arr, temp, 0, arr.size() - 1);
}

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << countInversions(arr) << endl;
    }

    return 0;
}