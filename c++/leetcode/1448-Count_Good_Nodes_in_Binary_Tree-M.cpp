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
private:
    int cnt;
    
public:
    void helper(TreeNode* root, int maximum) {
        if (!root) return;
        if (root->val >= maximum) {
            cnt++;
        }
        maximum = max(root->val, maximum);
        helper(root->left, maximum);
        helper(root->right, maximum);
    }
    
    int goodNodes(TreeNode* root) {
        cnt = 0;
        helper(root, INT_MIN);
        return cnt;
    }
};

//

class Solution {
public:
    int goodNodes(TreeNode* root) {
        function<int(TreeNode*, int)> traverse;
        traverse = [&](TreeNode* node, int max_val) {
            if (!node) return 0;
            int good_ones = node->val >= max_val;
            max_val = max(node->val, max_val);
            good_ones += traverse(node->left, max_val);
            good_ones += traverse(node->right, max_val);
            return good_ones;
        };
        return traverse(root, INT_MIN);
    }
};
