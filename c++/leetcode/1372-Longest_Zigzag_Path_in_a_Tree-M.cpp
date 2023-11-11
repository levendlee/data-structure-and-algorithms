class Solution {
public:
    int longestZigZag(TreeNode* root) {
        int longest = 0;

        function<pair<int,int>(TreeNode*)> traverse;
        traverse = [&](TreeNode* node) -> pair<int, int> {
            if (!node) return {0, 0};
            auto [ll, lr] = traverse(node->left);
            auto [rl, rr] = traverse(node->right);
            longest = max({longest, lr + 1, rl + 1});
            return {lr + 1, rl + 1};
        };

        traverse(root);
        return longest - 1;
    }
};
