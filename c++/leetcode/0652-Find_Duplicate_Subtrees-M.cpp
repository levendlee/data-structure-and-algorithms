// 652 Find Duplicate Subtrees
// https://leetcode.com/problems/find-duplicate-subtrees

// version: 1; create time: 2020-01-29 22:37:58;
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
    map<pair<int,int>, vector<TreeNode*>> root_map_;

public:
    int postOrder(TreeNode* root) {
        if (!root) return 0;
        const int cnt = postOrder(root->left) + postOrder(root->right) + 1;
        const auto key = std::make_pair(root->val, cnt);
        root_map_[key].push_back(root);
        return cnt;
    }

    bool isSame(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2 || root1->val != root2->val) return false;
        if (!isSame(root1->left, root2->left) || !isSame(root1->right, root2->right)) return false;
        return true;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_set<TreeNode*> checked;

        postOrder(root);
        for (const auto& p : root_map_) {
            const auto& vec = p.second;
            const int n = vec.size();

            if (n == 1) continue;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (isSame(vec[i], vec[j])) {
                        if (!checked.count(vec[i]) && !checked.count(vec[j])) {
                            res.push_back(vec[i]);
                        }
                        checked.insert(vec[i]);
                        checked.insert(vec[j]);
                    }
                }
            }
        }

        return res;
    }
};
