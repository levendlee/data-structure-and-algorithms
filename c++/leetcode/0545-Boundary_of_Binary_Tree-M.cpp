// 545 Boundary of Binary Tree
// https://leetcode.com/problems/boundary-of-binary-tree

// version: 1; create time: 2020-01-04 16:17:47;
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
    void getLeaves(TreeNode* root, vector<int>& vec) {
        if (!root) return;
        if (!root->left && !root->right) {
            vec.push_back(root->val);
        }
        getLeaves(root->left, vec);
        getLeaves(root->right, vec);
    }

    void getLeftBoundary(TreeNode* root, vector<int>& vec) {
        if (!root) return;
        if (!root->left && !root->right) return;
        vec.push_back(root->val);
        if (root->left) {
            getLeftBoundary(root->left, vec);
        } else if (root->right) {
            getLeftBoundary(root->right, vec);
        }
    }

    void getRightBoundary(TreeNode* root, vector<int>& vec) {
        if (!root) return;
        if (!root->left && !root->right) return;
        if (root->right) {
            getRightBoundary(root->right, vec);
        } else if (root->left) {
            getRightBoundary(root->left, vec);
        }
        vec.push_back(root->val);
    }

    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        res.push_back(root->val);
        if (!root->left && !root->right) return res;
        if (root->left) getLeftBoundary(root->left, res);
        getLeaves(root, res);
        if (root->right) getRightBoundary(root->right, res);
        return res;
    }
};
