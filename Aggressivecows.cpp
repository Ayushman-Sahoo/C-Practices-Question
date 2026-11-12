/*Aggressive cows
Farmer John has built a new long barn, with N (2 ≤ N ≤ 100,000) stalls. The stalls are located along a straight line at positions 
x1 ... xN (0 ≤ xi ≤ 1,000,000,000).

His C (2 ≤ C ≤ N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent 
the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them
is as large as possible. What is the largest minimum distance?

Input
t – the number of test cases, then t test cases follows.

Line 1: Two space-separated integers: N and C
Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.

Example
Input:
1
5 3
1
2
8
4
9

Output:
3
Explanation
FJ can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlace(vector<int>& stalls, int cows, int distance) {
    int count = 1;
    int lastPosition = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPosition >= distance) {
            count++;
            lastPosition = stalls[i];

            if (count == cows) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, c;
        cin >> n >> c;

        vector<int> stalls(n);

        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }

        // Sort stall positions
        sort(stalls.begin(), stalls.end());

        int left = 0;
        int right = stalls[n - 1] - stalls[0];
        int answer = 0;

        // Binary Search on the answer
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canPlace(stalls, c, mid)) {
                // This distance is possible
                answer = mid;
                left = mid + 1;
            }
            else {
                // This distance is not possible
                right = mid - 1;
            }
        }

        cout << answer << endl;
    }

    return 0;
}