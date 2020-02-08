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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root) return res;

        queue<TreeNode*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            const int size = bfs.size();
            double sum = 0;
            for (int i = 0; i < size; ++i) {
                auto node = bfs.front(); bfs.pop();
                sum += node->val;
                if (node->left) bfs.push(node->left);
                if (node->right) bfs.push(node->right);
            }
            res.push_back(1.0 * sum / size);
        }
        return res;
    }
};