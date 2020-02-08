/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* preOrder(vector<int>& preorder, int& i, int min_v, int max_v) {
        if (i == preorder.size()) return nullptr;
        int v = preorder[i];
        if (v < min_v || v > max_v) return nullptr;
        ++i;
        TreeNode* root = new TreeNode(v);
        root->left = preOrder(preorder, i, min_v, v);
        root->right = preOrder(preorder, i, v, max_v);
        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return preOrder(preorder, i, INT_MIN, INT_MAX);
    }
};