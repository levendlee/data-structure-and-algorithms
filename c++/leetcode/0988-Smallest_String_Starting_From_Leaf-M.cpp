class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string res;

        function<bool(TreeNode*, string&)> dfs;
        dfs = [&](TreeNode* node, string& s) {
            if (!node) return false;
            s.push_back(node->val + 'a');
            auto l = dfs(node->left, s);
            auto r = dfs(node->right, s);
            if (!l && !r) {
                reverse(s.begin(), s.end());
                if (res.empty() || res > s) res = s;
                reverse(s.begin(), s.end());
            }
            s.pop_back();
            return true;
        };

        string holder;
        dfs(root, holder);
        return res;
    }
};
