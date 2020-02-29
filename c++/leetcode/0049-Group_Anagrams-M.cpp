// 49 Group Anagrams
// https://leetcode.com/problems/group-anagrams

// version: 1; create time: 2020-01-04 17:05:56;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const auto& str : strs) {
            auto tmp = str;
            std::sort(tmp.begin(), tmp.end());
            groups[tmp].push_back(str);
        }
        vector<vector<string>> res;
        for (const auto& p : groups) {
            res.push_back(std::move(p.second));
        }
        return res;
    }
};
