// 111 Minimum Depth of Binary Tree
// https://leetcode.com/problems/minimum-depth-of-binary-tree

// version: 1; create time: 2020-02-07 22:34:29;
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;

        queue<TreeNode*> bfs;
        bfs.push(root);
        int depth = 1;
        while (!bfs.empty()) {
            const int size = bfs.size();
            for (int i = 0; i < size; ++i) {
                auto node = bfs.front(); bfs.pop();
                if (!node->left && !node->right) return depth;
                if (node->left) bfs.push(node->left);
                if (node->right) bfs.push(node->right);
            }
            ++depth;
        }

        return depth;
    }
};

//

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;

        int depth = 1;
        queue<TreeNode*> bfs;
        bfs.push(root);

        while (!bfs.empty()) {
            int search_space = bfs.size();
            for (int i = 0; i < search_space; ++i) {
                TreeNode* node = bfs.front();
                bfs.pop();
                if (!node->left && !node->right) return depth;
                if (node->left) bfs.push(node->left);
                if (node->right) bfs.push(node->right);
            }
            ++depth;
        }

        return depth;
    }
};
