class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> window_max;
        deque<int> window;
        for (int i = 0; i < nums.size(); ++i) {
            while (!window.empty() && window.back() < nums[i]) {
                window.pop_back();
            }
            window.push_back(nums[i]);
            if (i >= k - 1) {
                window_max.push_back(window.front());
                if (nums[i - k + 1] == window.front()) {
                    window.pop_front();
                }
            }
        }
        return window_max;
    }
};