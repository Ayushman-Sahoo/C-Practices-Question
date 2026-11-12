/*84. Largest Rectangle in Histogram
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the 
largest rectangle in the histogram.

Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:

Input: heights = [2,4]
Output: 4

Constraints:

1 <= heights.length <= 10^5
0 <= heights[i] <= 10^4
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    
    stack<int> st;
    int maxArea = 0;
    
    for (int i = 0; i <= heights.size(); i++) {
        
        int currentHeight = (i == heights.size()) ? 0 : heights[i];
        
        while (!st.empty() && currentHeight < heights[st.top()]) {
            
            int height = heights[st.top()];
            st.pop();
            
            int width;
            
            if (st.empty()) {
                width = i;
            } else {
                width = i - st.top() - 1;
            }
            
            int area = height * width;
            maxArea = max(maxArea, area);
        }
        
        st.push(i);
    }
    
    return maxArea;
}

int main() {
    
    int n;
    
    cout << "Enter number of bars: ";
    cin >> n;
    
    vector<int> heights(n);
    
    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    
    int result = largestRectangleArea(heights);
    
    cout << "Largest Rectangle Area = " << result << endl;
    
    return 0;
}