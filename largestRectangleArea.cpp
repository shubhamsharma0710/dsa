#include<iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxarea = 0;
        int n = heights.size();
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int ele = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxarea = max(maxarea, heights[ele] * (nse - pse - 1));
            }
            st.push(i);
        }
        
        while(!st.empty()) {
            int nse = n;
            int ele = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxarea = max(maxarea, heights[ele] * (nse - pse - 1));
        }
        
        return maxarea;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result = sol.largestRectangleArea(heights);
    cout << "Output: " << result << endl; 
    return 0;
}
