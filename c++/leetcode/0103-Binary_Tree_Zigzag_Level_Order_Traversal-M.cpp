class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> zigzag;
        queue<TreeNode*> bfs;
        bfs.push(root);
        bool left2right = true;
        while (!bfs.empty()) {
            int size = bfs.size();
            vector<int> order;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = bfs.front();
                bfs.pop();
                order.push_back(node->val);
                if (node->left) bfs.push(node->left);
                if (node->right) bfs.push(node->right);
            }
            if (!left2right) {
                reverse(order.begin(), order.end());
            }
            left2right = !left2right;
            zigzag.emplace_back(move(order));
        }

        return zigzag;
    }
};
