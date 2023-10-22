// 230 Kth Smallest Element in a BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst

// version: 1; create time: 2020-02-10 14:24:03;
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
    int idx_;
    int kth_;

    bool inOrder(TreeNode* root) {
        if (!root) return false;
        if (inOrder(root->left)) return true;
        if (++idx_ == k_) {
            kth_ = root->val;
            return true;
        }
        if (inOrder(root->right)) return true;
        return false;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        k_ = k;
        idx_ = 0;
        kth_ = 0;
        inOrder(root);
        return kth_;
    }
};

// 2023/10/21

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while (root) {
            stk.push(root);
            root = root->left;
        }

        for (int i = 0; i < k - 1; ++i) {
            TreeNode* node = stk.top();
            stk.pop();
            if (node->right) {
                node = node->right;
                while (node) {
                    stk.push(node);
                    node = node->left;
                }
            }
        }

        return stk.top()->val;
    }
};
