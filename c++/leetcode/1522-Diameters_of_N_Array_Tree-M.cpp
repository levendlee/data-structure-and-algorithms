class Solution {
public:
    int diameter(Node* root) {
        int d = 0;

        function<int(Node*)> dfs;
        dfs = [&](Node* node) {
            if (!node) return 0;
            int d0 = 0, d1 = 0;
            for (Node* c : node->children) {
                int depth = dfs(c);
                if (depth > d0) {
                    d1 = d0;
                    d0 = depth;
                } else if (depth > d1) {
                    d1 = depth;
                }
            }
            d = max(d, d0 + d1);
            return d0 + 1;
        };
        dfs(root);

        return d;
    }
};
