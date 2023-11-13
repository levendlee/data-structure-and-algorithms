class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> combinations;

        function<void(int, int, vector<int>&)> dfs;
        dfs = [&](int idx, int sum, vector<int>& vec) {
            if (vec.size() == k) {
                if (sum == n) {
                    combinations.push_back(vec);
                }
                return;
            }
            for (int i = idx; i <= 9; ++i) {
                sum += i;
                vec.push_back(i);
                dfs(i + 1, sum, vec);
                sum -= i;
                vec.pop_back();
            }
        };

        vector<int> cur;
        dfs(1, 0, cur);
        return combinations;
    }
};
