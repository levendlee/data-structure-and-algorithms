class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        function<bool(TreeNode*, TreeNode*)> dfs;
        dfs = [&](TreeNode* p, TreeNode* q) {
            if (!p && !q) return true;
            if (!p || !q || p->val != q->val) return false;
            return dfs(p->left, q->left) && dfs(p->right, q->right);
        };
        return dfs(p, q);
    }
};
