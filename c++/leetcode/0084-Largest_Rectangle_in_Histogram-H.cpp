class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();

        stack<int> stk;
        // Leftmost.
        stk.push(-1);

        int max_area = 0;
        for (int i = 0; i < n; ++i) {
            while (stk.top() != -1 && heights[stk.top()] >= heights[i]) {
                int cur_height = heights[stk.top()];
                stk.pop();
                // Excludes both current location and previous location
                int cur_width = i - stk.top() - 1;
                max_area = max(max_area, cur_height * cur_width);
            }
            stk.push(i);
        }
        while (stk.top() != -1) {
            int cur_height = heights[stk.top()];
            stk.pop();
            int cur_width = n - stk.top() - 1;
            max_area = max(max_area, cur_height * cur_width);
        }
        return max_area;
    }
};
