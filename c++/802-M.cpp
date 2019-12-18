class Solution {
public:
    bool checkAcyclic(const vector<vector<int>>& graph,
                   vector<bool>& acyclic,
                   vector<bool>& visited,
                   vector<bool>& curpath,
                   int node)
    {
        if (curpath[node]) {
            return false;
        }

        if (visited[node]) {
            return acyclic[node];
        }

        curpath[node] = true;
        bool is_acyclic = true;
        for (const auto prev: graph[node]) {
            is_acyclic &= checkAcyclic(graph, acyclic, visited, curpath, prev);
        }
        curpath[node] = false;
        visited[node] = true;

        acyclic[node] = is_acyclic;
        return is_acyclic;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int n = graph.size();

        vector<bool> acyclic(n, false);
        vector<bool> visited(n, false);
        vector<bool> curpath(n, false);

        for (int i = 0; i < n; ++i) {
            checkAcyclic(graph, acyclic, visited, curpath, i);
        }

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (acyclic[i]) {
                res.push_back(i);
            }
        }

        return res;
    }
};