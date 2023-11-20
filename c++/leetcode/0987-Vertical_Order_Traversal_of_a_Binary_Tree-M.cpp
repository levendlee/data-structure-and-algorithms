// 987 Vertical Order Traversal of a Binary Tree
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

// version: 1; create time: 2020-02-05 23:51:38;
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

//

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};

        queue<pair<TreeNode*, int>> bfs;
        bfs.push({root, 0});

        int i = 0;
        int min_col = 0, max_col = 0;
        unordered_map<int, vector<int>> cols;
        while(!bfs.empty()) {
            int search_space = bfs.size();
            unordered_map<int, vector<int>> cur_cols;

            for (int k = 0; k < search_space; ++k) {
                auto [node, j] = bfs.front();
                bfs.pop();
                min_col = min(min_col, j);
                max_col = max(max_col, j);
                cur_cols[j].push_back(node->val);
                if (node->left) bfs.push({node->left, j - 1});
                if (node->right) bfs.push({node->right, j + 1});
            }

            for (auto& [j, vals] : cur_cols) {
                sort(vals.begin(), vals.end());
                cols[j].insert(cols[j].end(), vals.begin(), vals.end());
            }
        }

        vector<vector<int>> res;
        for (int j = min_col; j <= max_col; ++j) {
            res.emplace_back(move(cols[j]));
        }
        return res;
    }
};
