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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> parent;

        stack<TreeNode*> stk;
        TreeNode* node = root;
        while (!stk.empty() || node) {
            if (node) {
                if (node->left) parent[node->left] = node;
                if (node->right) parent[node->right] = node;
                stk.push(node);
                node = node->left;
            } else {
                node = stk.top()->right; stk.pop();
            }
        }

        unordered_set<TreeNode*> visited;
        visited.insert(nullptr);
        visited.insert(target);

        queue<TreeNode*> bfs;
        bfs.push(target);

        const auto add_node = [&](TreeNode* node) {
            if (!visited.count(node)) {
                bfs.push(node);
                visited.insert(node);
            }
        };

        while (K--) {
            const auto size = bfs.size();
            for (int i = 0; i < size; ++i) {
                auto node = bfs.front(); bfs.pop();
                add_node(node->left);
                add_node(node->right);
                add_node(parent[node]);
            }
        }

        vector<int> res;
        while (!bfs.empty()) {
            res.push_back(bfs.front()->val); bfs.pop();
        }

        return res;
    }
};