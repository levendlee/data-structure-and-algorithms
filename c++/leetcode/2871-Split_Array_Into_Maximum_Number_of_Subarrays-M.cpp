class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int min_num = (1LL << 32) - 1;
        for (int n : nums) {
            min_num &= n;
        }

        int num_subarrays = 0;
        bool filled = false;
        int cur_num = (1LL << 32) - 1;
        for (int n : nums) {
            cur_num &= n;
            if (cur_num == 0) {
                ++num_subarrays;
                cur_num = (1LL << 32) - 1;
            } else if (cur_num == min_num && !filled) {
                ++num_subarrays;
                filled = true;
                cur_num = (1LL << 32) - 1;
            }
        }
        return num_subarrays;
    }
};

