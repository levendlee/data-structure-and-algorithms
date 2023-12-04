class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        if (nums.empty()) return 0;

        int num_subsets = 1;

        // Group numbers based on reminder divided by k
        vector<vector<int>> groups(k);
        for(int n : nums) {
            groups[n % k].push_back(n);
        }

        // Sort numbers in each group.
        for (int i = 0; i < k; ++i) {
            auto& vec = groups[i];
            if (vec.empty()) continue;

            sort(vec.begin(), vec.end());

            // Use dynamic programming.
            // Number of cases not including the current number.
            int dp0 = 1;
            // Number of cases including the current number.
            int dp1 = 0;
            for (int j = 0; j < vec.size(); ++j) {
                // For the first element, we can add unconditionally.
                int pre = j == 0 ? vec[j] : vec[j - 1];
                int cur = vec[j];
                int cnt = 1;
                // Handle duplicates
                while (j + 1 < vec.size() && vec[j + 1] == vec[j]) {
                    ++j;
                    ++cnt;
                }
                // Can always choose to not include current one.
                int ndp0 = dp0 + dp1;
                // Cannot include current one if include previous one.
                int ndp1 = dp0 + ((cur - pre == k) ? 0 : dp1);
                // Including has 2 ^ cnt - 1 cases.
                ndp1 = ndp1 * ((1 << cnt) - 1);
                dp0 = ndp0;
                dp1 = ndp1;
            }

            // Total number of cases in current group. Permutation.
            num_subsets *= dp0 + dp1;
        }

        // Exclude the case of all empty.
        return num_subsets - 1;

    }
};
