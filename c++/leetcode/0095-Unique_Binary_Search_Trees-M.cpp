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
    vector<TreeNode*> generateTrees(int n) {
        function<vector<TreeNode*>(int, int)> generateTreeHelper;
        function<vector<TreeNode*>(int, int)> generateTreeMemo;
        unordered_map<int, vector<TreeNode*>> memo;
        generateTreeMemo = [&](int lo, int hi) -> vector<TreeNode*> {
            int key = lo * n + hi;
            auto iter = memo.find(key);
            if (iter != memo.end()) {
                return iter->second;
            }
            auto trees = generateTreeHelper(lo, hi);
            memo[key] = trees;
            return trees;
        };

        generateTreeHelper = [&](int lo, int hi) -> vector<TreeNode*> {
            if (lo > hi) return {nullptr};
            if (lo == hi) return {new TreeNode(lo)};
            vector<TreeNode*> res;
            for (int mid = lo; mid <= hi; ++mid) {
                auto ltrees = generateTreeMemo(lo, mid - 1);
                auto rtrees = generateTreeMemo(mid + 1, hi);
                for (auto l : ltrees) {
                    for (auto r : rtrees) {
                        TreeNode* root = new TreeNode(mid);
                        root->left = l;
                        root->right = r;
                        res.push_back(root);
                    }
                }
            }
            return res;
        };
        return generateTreeHelper(1, n);
    }
};