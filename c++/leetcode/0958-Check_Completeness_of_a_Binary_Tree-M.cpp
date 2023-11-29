// 958 Check Completeness of a Binary Tree
// https://leetcode.com/problems/check-completeness-of-a-binary-tree

// version: 1; create time: 2020-02-06 00:12:55;
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
    bool complete_;

public:
    pair<int, int> inOrderTraversal(TreeNode* node, int depth) {
        if (!node) return {depth, depth};
        auto ld = inOrderTraversal(node->left, depth + 1);
        auto rd = inOrderTraversal(node->right, depth + 1);
        if ((ld.second < rd.first) || (ld.first > rd.second + 1)) complete_ = false;
        return {ld.first, rd.second};
    }

    bool isCompleteTree(TreeNode* root) {
        complete_ = true;
        inOrderTraversal(root, 0);
        return complete_;
    }
};

//

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        bool is_complete = true;

        function<pair<int, int>(TreeNode*, int)> dfs;
        dfs = [&](TreeNode* node, int depth) -> pair<int, int> {
            if (!node) return {depth, depth};
            auto [l_min, l_max] = dfs(node->left, depth + 1);
            auto [r_min, r_max] = dfs(node->right, depth + 1);
            if (r_max > l_min || l_max - r_min > 1) {
                is_complete = false;
                return {0, 0};
            }
            return {r_min, l_max};
        };

        dfs(root, 0);
        return is_complete;
    }
};
