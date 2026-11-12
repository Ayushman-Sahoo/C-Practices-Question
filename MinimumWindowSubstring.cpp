/*76. Minimum Window Substring
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t 
(including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 
Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) {
            return "";
        }

        int need[128] = {0};

        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int right = 0;

        int required = t.length();
        int minLength = INT_MAX;
        int start = 0;

        while (right < s.length()) {
            char c = s[right];

            if (need[c] > 0) {
                required--;
            }

            need[c]--;
            right++;

            while (required == 0) {
                if (right - left < minLength) {
                    minLength = right - left;
                    start = left;
                }

                char leftChar = s[left];
                need[leftChar]++;

                if (need[leftChar] > 0) {
                    required++;
                }

                left++;
            }
        }

        if (minLength == INT_MAX) {
            return "";
        }

        return s.substr(start, minLength);
    }
};

int main() {
    string s, t;

    cout << "Enter s: ";
    cin >> s;

    cout << "Enter t: ";
    cin >> t;

    Solution obj;

    cout << "Minimum Window: " << obj.minWindow(s, t) << endl;

    return 0;
}