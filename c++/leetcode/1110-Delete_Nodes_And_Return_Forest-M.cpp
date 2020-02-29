// 1110 Delete Nodes And Return Forest
// https://leetcode.com/problems/delete-nodes-and-return-forest

// version: 2; create time: 2020-02-17 23:12:52;
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


// version: 1; create time: 2019-10-22 21:27:24;
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
