class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        std::unordered_map<Node *, Node *> copy_map;
        std::function<void(Node *)> dfs_copy;
        dfs_copy = [&](Node *node)
        {
            if (!node || copy_map.count(node))
                return;
            copy_map[node] = new Node(node->val);
            for (auto n : node->neighbors)
            {
                dfs_copy(n);
            }
        };
        dfs_copy(node);

        std::unordered_set<Node *> redirect_set;
        std::function<void(Node *)> dfs_redirect;
        dfs_redirect = [&](Node *node)
        {
            if (!node || redirect_set.count(node))
                return;
            redirect_set.insert(node);
            for (auto n : node->neighbors)
            {
                copy_map[node]->neighbors.push_back(copy_map[n]);
                dfs_redirect(n);
            }
        };
        dfs_redirect(node);

        return copy_map[node];
    }
};

//

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        unordered_map<Node *, Node *> copy_map;
        function<void(Node *)> copy_node;
        copy_node = [&](Node *original)
        {
            if (!original || copy_map.count(original))
                return;
            copy_map[original] = new Node(original->val);
            for (auto neigh : original->neighbors)
            {
                copy_node(neigh);
            }
        };

        function<void(Node *)> copy_neighbors;
        copy_neighbors = [&](Node *original)
        {
            if (!original ||
                copy_map[original]->neighbors.size() == original->neighbors.size())
                return;
            for (auto neigh : original->neighbors)
            {
                copy_map[original]->neighbors.push_back(copy_map[neigh]);
            }
            for (auto neigh : original->neighbors)
            {
                copy_neighbors(neigh);
            }
        };

        copy_node(node);
        copy_neighbors(node);

        return copy_map[node];
    }
};
