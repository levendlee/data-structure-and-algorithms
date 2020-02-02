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
public:
    void inOrder(TreeNode* root, const int sum, const int target, vector<vector<int>>& res, vector<int>& cur) {
        if (!root) return;
        int cur_sum = sum + root->val;
        cur.push_back(root->val);
        if (!root->left && !root->right) {
            if (cur_sum == target) res.push_back(cur);
        } else {
            inOrder(root->left, cur_sum, target, res, cur);
            inOrder(root->right, cur_sum, target, res, cur);
        }
        cur.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur;
        inOrder(root, 0, sum, res, cur);
        return res;
    }
};