/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        function<array<int64_t, 3>(TreeNode*)> dfs;
        // (install, don't install not covered, don't install covered.
        dfs = [&](TreeNode* root) -> array<int64_t, 3> {
            if (!root) return {INT_MAX, 0, 0};
            auto lret = dfs(root->left);
            auto rret = dfs(root->right);
            array<int64_t, 3> ret;
            // install
            ret[0] = *min_element(lret.begin(), lret.end()) +
                     *min_element(rret.begin(), rret.end()) +
                     1;
            // don't install. not covered.
            ret[1] = min(lret[0], lret[2]) + min(rret[0], rret[2]);
            // don't install. covered.
            ret[2] = min(min(lret[0], lret[2]) + rret[0],
                         min(rret[0], rret[2]) + lret[0]);
            return ret;
        };
        auto ret = dfs(root);
        return min(ret[0], ret[2]);
    }
};