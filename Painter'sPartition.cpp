/*Painter's Partition
Problem

There is fence which consists of n wooden blocks with each block having a number written on it represented by an array a. The 
painter is also given two numbers l and r. He is given the task to paint the fence using at most n colors. But there are certain 
conditions which the painter must follow while painting:

He has to paint the fence in sequential manner from left to right i.e., first paint the first block then second block and so on 
without leaving any block not being painted.
He will also use colors in sequential manner i.e., first paint with 1st color, then with 2nd color and so on. Note that he can 
paint any number of blocks sequentially with a single color and a color once used cannot be reused.
The sum of numbers written on blocks painted with same color must lie between l and r (both inclusive).

The painter wants to know in how many ways can he paint the fence. Since the answer can be large, find the answer modulo 
1000000007.

Input Format

First line contains 3 space separated denoting the values of n, l and r
(1 ≤ n ≤ 10^5, 1 ≤ l ≤ r ≤ 10^12)

Next line contains n space separated integers denoting the values of array a

(1 ≤ a[i] ≤ r).

Output Format

Print the answer in a single line.

Sample Input
5 3 12
3 5 1 2 6
Sample Output
8
*/

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int n;
    long long l, r;

    cin >> n >> l >> r;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Prefix sum
    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + a[i];
    }

    // dp[i] = number of ways for first i elements
    vector<long long> dp(n + 1, 0);

    // prefixDP[i] = dp[0] + dp[1] + ... + dp[i]
    vector<long long> prefixDP(n + 1, 0);

    dp[0] = 1;
    prefixDP[0] = 1;

    int left = 0;
    int right = 0;

    for (int i = 1; i <= n; i++) {

        while (left < i && prefix[i] - prefix[left] > r) {
            left++;
        }

        while (right < i && prefix[i] - prefix[right] >= l) {
            right++;
        }

        if (right > left) {
            dp[i] = prefixDP[right - 1];

            if (left > 0) {
                dp[i] -= prefixDP[left - 1];
            }

            dp[i] = (dp[i] + MOD) % MOD;
        }

        prefixDP[i] = (prefixDP[i - 1] + dp[i]) % MOD;
    }

    cout << dp[n] << endl;

    return 0;
}