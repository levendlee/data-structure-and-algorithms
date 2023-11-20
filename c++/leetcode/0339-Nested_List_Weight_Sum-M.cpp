public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int depth_sum = 0;

        function<int(const NestedInteger&, int)> dfs;
        dfs = [&](const NestedInteger& ni, int depth) {
            int sum = 0;
            if (ni.isInteger()) {
                return depth * ni.getInteger();
            }
            for (const auto& ni : ni.getList()) {
                sum += dfs(ni, depth + 1);
            }
            return sum;
        };

        for (const auto& ni : nestedList) {
            depth_sum += dfs(ni, 1);
        }
        return depth_sum;
    }
};
