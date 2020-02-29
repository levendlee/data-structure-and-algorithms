// 889 Construct Binary Tree from Preorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal

// version: 1; create time: 2019-10-28 21:11:22;
class Solution {
public:
    TreeNode* constructHelper(const vector<int>& pre, int pre_r, const vector<int>& post, int post_s, int post_e) {
        if (post_s > post_e) return nullptr;

        TreeNode* root = new TreeNode(post[post_e]);
        int post_l = std::find(post.begin() + post_s, post.begin() + post_e, pre[pre_r + 1]) - post.begin();
        post_l = post_l < post_e ? post_l : (post_s - 1);
        root->left = constructHelper(pre, pre_r + 1, post, post_s, post_l);
        root->right = constructHelper(pre, pre_r + post_l - post_s + 2, post, post_l + 1, post_e - 1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        const int n = post.size();
        return constructHelper(pre, 0, post, 0, n - 1);
    }
};
