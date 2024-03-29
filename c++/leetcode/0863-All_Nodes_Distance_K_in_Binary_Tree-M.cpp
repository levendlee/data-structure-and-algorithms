// 863 All Nodes Distance K in Binary Tree
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

// version: 1; create time: 2020-02-05 23:16:42;
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

//

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> results;

        unordered_map<TreeNode*, TreeNode*> parents;
        function<void(TreeNode*, TreeNode*)> dfs;
        dfs = [&](TreeNode* cur, TreeNode* pre) {
            if (!cur) return;
            parents[cur] = pre;
            dfs(cur->left, cur);
            dfs(cur->right, cur);
        };
        dfs(root, nullptr);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> bfs;
        bfs.push(target);

        for (int i = 0; i < k; ++i) {
            int search_space = bfs.size();
            for (int j = 0; j < search_space; ++j) {
                auto node = bfs.front();
                bfs.pop();
                visited.insert(node);

                TreeNode* p = parents[node], *l = node->left, *r = node->right;
                if (p && !visited.count(p)) bfs.push(p);
                if (l && !visited.count(l)) bfs.push(l);
                if (r && !visited.count(r)) bfs.push(r);
            }
        }

        while (!bfs.empty()) {
            results.push_back(bfs.front()->val);
            bfs.pop();
        }
        return results;
    }
};
