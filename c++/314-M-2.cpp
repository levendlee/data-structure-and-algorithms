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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> lvec, rvec;
        queue<pair<TreeNode*, int>> bfs;
        bfs.push({root, 0});
        while (!bfs.empty()) {
            auto node = bfs.front().first;
            auto shift = bfs.front().second;
            bfs.pop();
            if (shift >= 0) {
                if (rvec.size() == shift) rvec.resize(shift + 1);
                rvec[shift].push_back(node->val);
            } else {
                if (lvec.size() == -shift-1) lvec.resize(-shift);
                lvec[-shift-1].push_back(node->val);
            }
            if (node->left) bfs.push({node->left, shift - 1});
            if (node->right) bfs.push({node->right, shift + 1});
        }

        reverse(lvec.begin(), lvec.end());
        for (auto& vec : rvec) {
            lvec.push_back(move(vec));
        }
        return lvec;
    }
};