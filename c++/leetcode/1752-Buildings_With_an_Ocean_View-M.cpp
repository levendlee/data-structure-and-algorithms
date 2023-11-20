class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> views;
        
        const int n = heights.size();
        int max_h = INT_MIN;
        for (int i = n - 1; i >= 0; --i) {
            if (heights[i] > max_h) {
                views.push_back(i);
            }
            max_h = max(max_h, heights[i]);
        }
        reverse(views.begin(), views.end());
        return views;
    }
};
