class Solution {
public:
    string alienOrder(vector<string>& words) {
        const int n = words.size();

        unordered_set<char> chars;
        for (const string& s : words) {
            for (char c : s) {
                chars.insert(c);
            }
        }
        unordered_map<char, vector<char>> edges;
        for (int k = 0; k < n - 1; ++k) {
            int i = 0;
            int m1 = words[k].size();
            int m2 = words[k+1].size();
            while (i < m1 && i < m2) {
                int c0 = words[k][i];
                int c1 = words[k+1][i];
                if (c0 != c1) {
                    edges[c1].push_back(c0);
                    break;
                }
                ++i;
            }
            if ((i == m1 || i == m2) && (m1 > m2)) return "";
        }

        string res;
        function<bool(char, unordered_set<char>&)> dfs;
        dfs = [&](char c, unordered_set<char>& visited) {
            if (res.find(c) != string::npos) return true;
            if (visited.count(c)) return false;
            visited.insert(c);
            for (char nc : edges[c]) {
                if (!dfs(nc, visited)) return false;
            }
            res.push_back(c);
            return true;
        };

        for (char c : chars) {
            if (res.find(c) != string::npos) continue;
            unordered_set<char> visited;
            if (!dfs(c, visited)) {
                return "";
            }
        }

        return res;
    }
};
