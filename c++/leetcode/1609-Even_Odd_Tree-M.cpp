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
    bool isEvenOddTree(TreeNode* root) {
        if (root == nullptr) return true;
        
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            const int size = q.size();
            long long pre = level & 0x1 ? INT_MAX + 1LL : INT_MIN - 1LL;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                const int cur = node->val;
                // std::cout << cur << "\n";
                if (level & 0x1) {
                    if (cur & 0x1 || cur >= pre) return false;
                    pre = cur;
                } else {
                    if (!(cur & 0x1) || cur <= pre) return false;
                    pre = cur;
                }
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ++level;
        }
        
        return true;
    }
};
