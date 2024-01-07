class Solution {
public:
    Node* connect(Node* root) {
        unordered_map<int, Node*> last_nodes;
        function<void(Node*, int)> dfs;
        dfs = [&](Node* node, int depth) {
            if (!node) return;

            Node*& last_node = last_nodes[depth];
            if (last_node) {
                last_node->next = node;
            }
            last_node = node;
            dfs(node->left, depth + 1);
            dfs(node->right, depth + 1);
        };
        dfs(root, 0);
        return root;
    }
};