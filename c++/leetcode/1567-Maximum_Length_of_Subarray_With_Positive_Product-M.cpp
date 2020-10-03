class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        const int n = nums.size();
        int pos = -1, neg = -1;
        int sign = 1;
        int max_len = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                pos = i;
                neg = -1;
                sign = 1;
            } else {
                int cur_sign = nums[i] > 0? 1 : -1;
                sign = sign * cur_sign;
                if (sign == 1) {
                    max_len = max(max_len, i - pos);
                } else if (sign == -1) {
                    if (neg == -1) {
                        neg = i;
                    }
                    max_len = max(max_len, i - neg);
                }
            }
        }
        return max_len;
    }
};
