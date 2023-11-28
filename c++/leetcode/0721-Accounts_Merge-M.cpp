class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> email2id;
        unordered_map<int, string> id2name;
        
        int id = 0;
        auto to_id = [&](const string& email) {
            auto iter = email2id.find(email);
            if (iter != email2id.end()) {
                return iter->second;
            } else {
                email2id[email] = id;
                return id++;
            }
        };

        for (const auto& vec: accounts) {
            const auto& name = vec[0];
            for (int i = 1; i < vec.size(); ++i) {
                int id0 = to_id(vec[i]);
                id2name[id0] = name;
            }
        }

        vector<int> parent(id);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find_f;
        find_f = [&](int i) {
            if (i != parent[i]) {
                parent[i] = find_f(parent[i]);
            }
            return parent[i];
        };

        auto union_f = [&](int i, int j) {
            int p0 = find_f(i);
            int p1 = find_f(j);
            parent[p0] = p1;
        };

        for (const auto& vec: accounts) {
            const auto& name = vec[0];
            for (int i = 1; i < vec.size(); ++i) {
                int id0 = to_id(vec[i]);
                for (int j = i + 1; j < vec.size(); ++j) {
                    int id1 = to_id(vec[j]);
                    union_f(id0, id1);
                }
            }
        }

        unordered_map<int, vector<string>> results;
        for (const auto& [email, id] : email2id) {
            results[find_f(id)].push_back(email);
        }
        vector<vector<string>> results_vec;
        for (auto& [id, vec] : results) {
            vec.push_back({id2name[id]});
            reverse(vec.begin(), vec.end());
            sort(vec.begin() + 1, vec.end());
            results_vec.emplace_back(move(vec));
        }
        return results_vec;
    }
};
