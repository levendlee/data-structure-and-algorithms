// 291 Word Pattern II
// https://leetcode.com/problems/word-pattern-ii

// version: 1; create time: 2020-02-10 11:13:58;
class Solution {
public:
    bool dfs(const string& p, int i, const string& s, int j,
             unordered_map<char, string>& maps, unordered_map<string, char>& rmaps) {
        if (i == p.size() && j == s.size()) return true;
        if (i == p.size() || j == s.size()) return false;
        if (maps.count(p[i])) {
            auto target = maps[p[i]];
            if (j + target.size() > s.size() || target != s.substr(j, target.size())) return false;
            else return dfs(p, i + 1, s, j + target.size(), maps, rmaps);
        } else {
            for (int k = j; k < s.size(); ++k) {
                auto substr = s.substr(j, k - j + 1);
                if (rmaps.count(substr)) continue;
                maps[p[i]] = substr;
                rmaps[substr] = p[i];
                if (dfs(p, i + 1, s, k + 1, maps, rmaps)) return true;
                maps.erase(p[i]);
                rmaps.erase(substr);
            }
        }
        return false;
    }

    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> maps;
        unordered_map<string, char> rmaps;
        return dfs(pattern, 0, str, 0, maps, rmaps);
    }
};
