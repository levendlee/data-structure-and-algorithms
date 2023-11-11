class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;

        function<int(TreeNode*)> traverse;
        traverse = [&](TreeNode* node) {
            if (!node) return 0;

            path.push_back(node->val);
            int cnt = 0;
            long long sum = 0;
            int n = path.size();
            for (int i = n - 1; i >= 0; --i) {
                sum += path[i];
                cnt += sum == targetSum;
            }
            cnt += traverse(node->left);
            cnt += traverse(node->right);
            path.pop_back();

            return cnt;
        };

        return traverse(root);
    }
};

//

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefix_sum;
        prefix_sum[0] = 1;

        function<int(TreeNode*, long long)> traverse;
        traverse = [&](TreeNode* node, long long sum) {
            if (!node) return 0;

            sum += node->val;
            int cnt = prefix_sum[sum - targetSum];
            ++prefix_sum[sum];
            cnt += traverse(node->left, sum) + traverse(node->right, sum);
            --prefix_sum[sum];

            return cnt;
        };

        return traverse(root, 0);
    }
};
