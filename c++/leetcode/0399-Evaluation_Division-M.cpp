class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        std::unordered_map<std::string, std::unordered_map<std::string, double>> edges;

        const int n = equations.size();
        for (int i = 0; i < n; ++i) {
            const auto& lhs = equations[i][0], rhs = equations[i][1];
            edges[lhs][rhs] = values[i];
            edges[rhs][lhs] = 1.0 / values[i];
        }

        std::unordered_set<std::string> visited;
        std::function<double(const std::string& src, const std::string& dst)> dfs;
        dfs = [&] (const std::string& src, const std::string& dst) {
            if (src == dst) {
                return 1.0;
            }
            if (visited.count(src)) {
                return -1.0;
            }
            visited.insert(src);
            for (auto& [intermediate, ratio]: edges[src]) {
                double res = ratio * dfs(intermediate, dst);
                if (res >= 0) {
                    visited.erase(src);
                    return res; 
                }
            }
            visited.erase(src);
            return -1.0;
        };

        std::vector<double> results;
        for (const auto& q : queries) {
            visited.clear();
            if (!edges.count(q[0]) || !edges.count(q[1])) {
                results.push_back(-1.0);
                continue;
            }
            results.push_back(dfs(q[0], q[1]));
        }
        return results;
    }
};
