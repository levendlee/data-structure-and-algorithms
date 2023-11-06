// 222 Count Complete Tree Nodes
// https://leetcode.com/problems/count-complete-tree-nodes

// version: 1; create time: 2020-02-18 00:13:43;
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
    int calcSize(TreeNode* root) {
        if (!root) return 0;

        auto lh = 1, rh = 1, mh = 1;
        auto node = root;
        while (node = node->left) ++lh;
        node = root;
        while (node = node->right) ++rh;
        if (lh == rh) {
            return (1 << lh) - 1;
        }
        if (root->left) {
            node = root->left; ++mh;
            while (node = node->right) ++mh;
        }
        if (lh != mh) {
            return calcSize(root->left) + (1 << (rh - 1));
        } else {
            return (1 << (lh - 1)) + calcSize(root->right);
        }
    }
public:
    int countNodes(TreeNode* root) {
        return calcSize(root);
    }
};

//

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int h = 0;
        auto node = root;
        while (node) {
            node = node->left;
            ++h;
        }

        int lo = 0, hi = (1 << (h - 1)) - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;

            auto node = root;
            int bits = h - 1;
            while (bits) {
                if ((mid >> (bits - 1)) & 0x1) {
                    node = node->right;
                } else {
                    node = node->left;
                }
                --bits;
            }
            if (node) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }

        return (1 << (h - 1)) + lo;

    }
};
