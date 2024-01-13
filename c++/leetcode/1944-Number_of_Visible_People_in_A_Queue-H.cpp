class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        // Bruce-Force
        // T: O(N^2). S: O(N)
        /*
        const int n = heights.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            int cur_h = heights[i];
            int max_h = INT_MIN;
            int seen = 0;
            for (int j = i + 1; j < n; ++j) {
                seen += min(heights[i], heights[j]) > max_h;
                max_h = max(max_h, heights[j]);
            }
            res[i] = seen;
        }
        */

        // T: O(N). S: O(N)
        stack<int> heights_ranking;
        const int n = heights.size();
        vector<int> res(n, 0);
        for (int i = n - 1; i >= 0; --i) {
            int total_elems = heights_ranking.size();
            while (!heights_ranking.empty() && heights_ranking.top() < heights[i]) {
                heights_ranking.pop();
            }
            int larger_elems = heights_ranking.size();
            int smaller_equal_elems = total_elems - larger_elems + (larger_elems > 0);
            res[i] = smaller_equal_elems;
            heights_ranking.push(heights[i]);
        }
        return res;
    }
};