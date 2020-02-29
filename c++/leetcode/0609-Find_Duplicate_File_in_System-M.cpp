// 609 Find Duplicate File in System
// https://leetcode.com/problems/find-duplicate-file-in-system

// version: 1; create time: 2020-01-29 21:26:13;
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> content_to_files;
        for (const auto& path : paths) {
            const int idx0 = path.find(' ');
            const auto base = path.substr(0, idx0);

            const int n = path.size();
            int i = idx0 + 1;
            while (i < n) {
                const auto idx1 = path.find('(', i);
                const auto idx2 = path.find(')', idx1 + 1);
                const auto filename = path.substr(i, idx1 - i);
                const auto content = path.substr(idx1 + 1, idx2 - idx1 - 1);
                content_to_files[content].push_back(base + '/' + filename);
                i = idx2 + 2;
            }
        }
        vector<vector<string>> res;
        for (auto& p : content_to_files) {
            if (p.second.size() < 2) continue;
            res.emplace_back(std::move(p.second));
        }
        return res;
    }
};
