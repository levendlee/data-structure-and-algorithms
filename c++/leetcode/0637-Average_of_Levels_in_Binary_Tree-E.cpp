class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sum;
        vector<int> cnt;

        function<void(TreeNode*, int)> dfs;
        dfs = [&](TreeNode* node, int depth) {
            if (!node) return;

            if (sum.size() < depth) {
                sum.push_back(0);
            }
            sum[depth - 1] += node->val;
            if (cnt.size() < depth) {
                cnt.push_back(0);
            }
            ++cnt[depth - 1];

            dfs(node->left, depth + 1);
            dfs(node->right, depth + 1);
        };

        dfs(root, 1);

        const int n = sum.size();
        vector<double> avg(n, 0);
        for (int i = 0; i < n; ++i) {
            avg[i] = sum[i] / cnt[i];
        }
        return avg;
    }
};
