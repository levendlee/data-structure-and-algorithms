// 1008 Construct Binary Search Tree from Preorder Traversal
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal

// version: 1; create time: 2020-02-07 23:23:30;
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
    TreeNode* preOrder(vector<int>& preorder, int& i, int min_v, int max_v) {
        if (i == preorder.size()) return nullptr;
        int v = preorder[i];
        if (v < min_v || v > max_v) return nullptr;
        ++i;
        TreeNode* root = new TreeNode(v);
        root->left = preOrder(preorder, i, min_v, v);
        root->right = preOrder(preorder, i, v, max_v);
        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return preOrder(preorder, i, INT_MIN, INT_MAX);
    }
};

//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        const int n = preorder.size();
        int i = 0;

        function<TreeNode*(int64_t, int64_t)> preorder_builder;
        preorder_builder = [&](int64_t lo, int64_t hi) {
            int64_t mid = preorder[i++];
            TreeNode* node = new TreeNode(mid);
            if (i < n && lo < preorder[i] && preorder[i] < mid) {
                node->left = preorder_builder(lo, mid);
            }
            if (i < n && mid < preorder[i] && preorder[i] < hi) {
                node->right = preorder_builder(mid, hi);
            }
            return node;
        };

        return preorder_builder(int64_t(INT_MIN) - 1, int64_t(INT_MAX) + 1);
    }
};