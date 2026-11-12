/*567. Permutation in String
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false

Constraints:

1 <= s1.length, s2.length <= 10^4
s1 and s2 consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {

    if (s1.length() > s2.length()) {
        return false;
    }

    int count1[26] = {0};
    int count2[26] = {0};

    // Count characters in s1
    for (char c : s1) {
        count1[c - 'a']++;
    }

    int windowSize = s1.length();

    // Create first window
    for (int i = 0; i < windowSize; i++) {
        count2[s2[i] - 'a']++;
    }

    // Check first window
    if (equal(count1, count1 + 26, count2)) {
        return true;
    }

    // Slide the window
    for (int i = windowSize; i < s2.length(); i++) {

        // Add new character
        count2[s2[i] - 'a']++;

        // Remove old character
        count2[s2[i - windowSize] - 'a']--;

        // Check current window
        if (equal(count1, count1 + 26, count2)) {
            return true;
        }
    }

    return false;
}

int main() {

    string s1, s2;

    cout << "Enter s1: ";
    cin >> s1;

    cout << "Enter s2: ";
    cin >> s2;

    if (checkInclusion(s1, s2)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}