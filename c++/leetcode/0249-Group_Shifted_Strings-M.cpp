// 249 Group Shifted Strings
// https://leetcode.com/problems/group-shifted-strings

// version: 1; create time: 2020-02-07 21:40:58;
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> groups;
        for (const auto& str : strings) {
            auto tmp = str;
            int d = tmp[0] - 'a';
            for (auto& c : tmp) {
                c = ((c - 'a') - d + 26) % 26 + 'a';
            }
            groups[tmp].push_back(str);
        }
        vector<vector<string>> res;
        for (const auto& p : groups) {
            res.push_back(p.second);
        }
        return res;
    }
};

//

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        auto is_shift = [&](const string& s0, const string& s1) {
            if (s0.size() != s1.size()) return false;
            const int n = s0.size();
            const int d = (s0[0] - s1[0] + 26) % 26;
            for (int i = 0; i < n; ++i) {
                if ((s0[i] - s1[i] + 26) % 26 != d) return false;
            }
            return true;
        };

        const int n = strings.size();
        vector<vector<int>> links(n);

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (is_shift(strings[i], strings[j])) {
                    links[i].push_back(j);
                }
            }
        }

        vector<bool> visited(n, false);
        function<void(int, vector<string>&)> dfs;
        dfs = [&](int i, vector<string>& group) {
            group.push_back(strings[i]);
            for (int j : links[i]) {
                if (visited[j]) continue;
                visited[j] = true;
                dfs(j, group);
            }
        };

        vector<vector<string>> results;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;

            vector<string> group;
            dfs(i, group);
            results.emplace_back(move(group));
        }

        return results;
    }
};

//

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> groups;

        for (const auto& s : strings) {
            string shifted = s;
            int shift = s[0] - 'a';
            for (char& c : shifted) {
                c = ((c - 'a' - shift + 26) % 26 + 'a');
            }
            groups[shifted].push_back(s);
        }

        vector<vector<string>> res;
        for (auto& [s, g] : groups) {
            res.emplace_back(move(g));
        }
        return res;
    }
};
