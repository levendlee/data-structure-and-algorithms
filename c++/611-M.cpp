class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        const int n = nums.size();
        if (n < 3) return 0;

        std::sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = 0; i + 2 < n; ++i) {
            int k = i + 1;
            for (int j = i + 1; j + 1 < n; ++j) {
                while (k < n && nums[i] + nums[j] > nums[k]) ++k;
                if (k > j) cnt += k - j - 1;
            }
        }

        return cnt;
    }
};