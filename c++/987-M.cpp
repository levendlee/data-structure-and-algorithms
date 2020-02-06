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
    void inOrder(TreeNode* root, int x, int y, priority_queue<vector<int>>& pq) {
        if (!root) return;
        pq.push({-x, y, -root->val});
        inOrder(root->left, x-1, y-1, pq);
        inOrder(root->right, x+1, y-1, pq);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;

        priority_queue<vector<int>> pq;
        inOrder(root, 0, 0, pq);
        int pre_x = INT_MIN;
        while (!pq.empty()) {
            auto vec = pq.top(); pq.pop();
            if (vec[0] != pre_x) {
                res.push_back({-vec[2]});
            } else {
                res.back().push_back({-vec[2]});
            }
            pre_x = vec[0];
        }
        return res;
    }
};