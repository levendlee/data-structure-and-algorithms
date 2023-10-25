class Solution {
public:
    Node* cloneGraph(Node* node) {
        std::unordered_map<Node*, Node*> copy_map;
        std::function<void(Node*)> dfs_copy;
        dfs_copy = [&](Node* node) {
            if (!node || copy_map.count(node)) return;
            copy_map[node] = new Node(node->val);
            for (auto n : node->neighbors) {
                dfs_copy(n);
            }
        };
        dfs_copy(node);

        std::unordered_set<Node*> redirect_set;
        std::function<void(Node*)> dfs_redirect;
        dfs_redirect = [&](Node* node) {
            if (!node || redirect_set.count(node)) return;
            redirect_set.insert(node);
            for (auto n : node->neighbors) {
                copy_map[node]->neighbors.push_back(copy_map[n]);
                dfs_redirect(n);
            }
        };
        dfs_redirect(node);

        return copy_map[node];
    }
};
