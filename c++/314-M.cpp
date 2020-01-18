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
    vector<vector<int>> left_;
    vector<vector<int>> right_;

public:
    void traversal(TreeNode* root) {
        if (!root) return;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto node = q.front().first;
            auto idx = q.front().second;
            q.pop();

            if (idx >= 0) {
                if (right_.size() <= idx) {
                    right_.push_back({});
                }
                right_[idx].push_back(node->val);
            } else {
                if (left_.size() < -idx) {
                    left_.push_back({});
                }
                left_[-idx-1].push_back(node->val);
            }
            if (node->left) q.push({node->left, idx - 1});
            if (node->right) q.push({node->right, idx + 1});
        }
    }

    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        left_.clear();
        right_.clear();
        traversal(root);

        std::reverse(left_.begin(), left_.end());
        for (auto& vec : left_) {
            res.emplace_back(std::move(vec));
        }
        for (auto& vec : right_) {
            res.emplace_back(std::move(vec));
        }
        return res;
    }
};