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
    vector<TreeNode*> roots_;

public:
    void postOrder(TreeNode*& root, bool p_deleted, const unordered_set<int>& to_delete) {
        if (!root) return;

        bool c_deleted = to_delete.count(root->val);
        postOrder(root->left, c_deleted, to_delete);
        postOrder(root->right, c_deleted, to_delete);

        if (p_deleted && !c_deleted) {
            roots_.push_back(root);
        }
        if (c_deleted) {
            //delete root; // leetcode does not allow actually delete nodes for unknown reason
            root = nullptr;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        std::unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        postOrder(root, true, to_delete_set);
        return roots_;
    }
};