class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int n = nums.size();
        if (k % n == 0) return;

        int cnt = 0;
        int start = 0;
        while (cnt < n) {
            int src = start;
            int dst = (src + k) % n;
            int tmp = nums[src];
            while (dst != start) {
                dst = (src + k) % n;
                std::swap(nums[dst], tmp);
                src = dst;
                ++cnt;
            }
            ++start;
        }
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int n = nums.size();
        k = k % n;
        if (k == 0) return;
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};
