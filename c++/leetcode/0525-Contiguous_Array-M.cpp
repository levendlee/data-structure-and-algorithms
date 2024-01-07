class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // T: O(N^2). S: O(N). TLE
        /*
        const int n = nums.size();
        vector<int> one_count(n + 1, 0), zero_count(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            one_count[i + 1] = one_count[i] + (nums[i] == 1);
            zero_count[i + 1] = zero_count[i] + (nums[i] == 0);
        }
        int max_len = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = n; j >= i + max_len; --j) {
                if (one_count[j] - one_count[i] == zero_count[j] - zero_count[i]) {
                    max_len = max(max_len, j - i);
                }
            }
        }
        return max_len;
        */
        // T: O(N). S: O(N).
        const int n = nums.size();
        
        unordered_map<int, int> first_diff_index;
        first_diff_index[0] = -1;

        int one_count = 0, zero_count = 0, max_len = 0;
        for (int i = 0; i < n; ++i) {
            one_count += nums[i] == 1;
            zero_count += nums[i] == 0;
            int diff = one_count - zero_count;
            if (first_diff_index.count(diff)) {
                max_len = max(max_len, i - first_diff_index[diff]);
            } else {
                first_diff_index[diff] = i;
            }
        }

        return max_len;
    }
};