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