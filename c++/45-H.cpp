class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return 0;

        int step = 0;
        int cur = 0, bound = 0;
        while (bound < n-1 ) {
            int new_bound = bound;
            for (int i = cur; i <= bound; ++i) {
                new_bound = std::max(new_bound, i + nums[i]);
            }
            cur = bound + 1;
            bound = new_bound;
            ++step;
        }
        return step;
    }
};