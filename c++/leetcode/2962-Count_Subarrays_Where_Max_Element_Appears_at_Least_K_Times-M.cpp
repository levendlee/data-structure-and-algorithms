class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        /*
        int n = nums.size();
        int max_num = *max_element(nums.begin(), nums.end());

        vector<int> counts(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            counts[i + 1] = counts[i] + (nums[i] == max_num);
        }

        long long res = 0;
        for (int i = 0; i < n; ++i) {
            if (counts[i + 1] < k) continue;
            auto iter = upper_bound(counts.begin(), counts.begin() + i + 1, counts[i + 1] - k);
            res += iter - counts.begin();
        }
        return res;
        */

        int n = nums.size();
        int max_num = *max_element(nums.begin(), nums.end());

        long long res = 0;
        int i = 0, j = 0, cnt = 0;
        while (j < n) {
            cnt += nums[j] == max_num;
            while (cnt - (nums[i] == max_num) >= k) {
                cnt -= nums[i] == max_num;
                ++i;
            }
            if (cnt == k) {
                //cout << j << ", " << i + 1 << "#\n";
                res += i + 1;
            }
            ++j;
        }
        return res;
    }
};