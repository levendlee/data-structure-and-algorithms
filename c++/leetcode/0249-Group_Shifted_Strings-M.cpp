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
