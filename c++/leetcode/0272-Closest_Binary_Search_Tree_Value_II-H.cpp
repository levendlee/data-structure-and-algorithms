// 272 Closest Binary Search Tree Value II
// https://leetcode.com/problems/closest-binary-search-tree-value-ii

// version: 1; create time: 2020-02-07 20:41:07;
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
    int k_;
    priority_queue<pair<double,int>> pq_;

    void searchBST(TreeNode* root, double target) {
        if (!root) return;

        double diff = abs(root->val - target);
        pq_.push({diff, root->val});
        if (pq_.size() > k_) {
            pq_.pop();
        }

        if (root->val > target) {
            searchBST(root->left, target);
            if (pq_.size() == k_ && pq_.top().first < diff) return;
            searchBST(root->right, target);
        } else {
            searchBST(root->right, target);
            if (pq_.size() == k_ && pq_.top().first < diff) return;
            searchBST(root->left, target);
        }
    }

public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        k_ = k;

        searchBST(root, target);

        vector<int> res;
        while (!pq_.empty()) {
            res.push_back(pq_.top().second); pq_.pop();
        }

        return res;
    }
};
