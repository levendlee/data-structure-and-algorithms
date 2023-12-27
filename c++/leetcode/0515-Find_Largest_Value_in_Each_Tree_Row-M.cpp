// 515 Find Largest Value in Each Tree Row
// https://leetcode.com/problems/find-largest-value-in-each-tree-row

// version: 1; create time: 2020-02-11 18:58:48;
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
    vector<int> res_;

    void preOrder(TreeNode* root, int depth) {
        if (!root) return;
        if (res_.size() <= depth) {
            res_.push_back(root->val);
        } else {
            res_[depth] = std::max(res_[depth], root->val);
        }
        preOrder(root->left, depth + 1);
        preOrder(root->right, depth + 1);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        preOrder(root, 0);
        return res_;
    }
};

//

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;

        function<void(TreeNode*, int)> dfs;
        dfs = [&](TreeNode* node, int level) {
            if (!node) return;
            if (res.size() <= level) {
                res.push_back(node->val);
            } else {
                res[level] = max(res[level], node->val);
            }
            dfs(node->left, level + 1);
            dfs(node->right, level + 1);
        };
        dfs(root, 0);

        return res;
    }
};
