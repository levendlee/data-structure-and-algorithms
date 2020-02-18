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
    TreeNode* postOrder(TreeNode* root, unordered_set<int>& to_delete, vector<TreeNode*>& forest) {
        if (!root) return root;
        TreeNode* ret = root;
        if (to_delete.count(root->val)) {
            ret = nullptr;
        }
        root->left = postOrder(root->left, to_delete, forest);
        root->right = postOrder(root->right, to_delete, forest);
        if (root->left && !ret) forest.push_back(root->left);
        if (root->right && !ret) forest.push_back(root->right);
        return ret;
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res;
        root = postOrder(root, delete_set, res);
        if (root) res.push_back(root);
        return res;
    }
};