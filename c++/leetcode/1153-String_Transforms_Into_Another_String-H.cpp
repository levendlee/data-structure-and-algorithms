// 1153 String Transforms Into Another String
// https://leetcode.com/problems/string-transforms-into-another-string

// version: 2; create time: 2020-02-16 23:24:28;
class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1.size() != str2.size()) return false;
        const int n = str1.size();

        vector<vector<int>> idx1(26), idx2(26);
        for (int i = 0; i < n; ++i) {
            idx1[str1[i] - 'a'].push_back(i);
            idx2[str2[i] - 'a'].push_back(i);
        }

        int bimapped = 0;
        for (int k = 0; k < 26; ++k) {
            if (idx1[k].empty()) continue;
            char matched_char = str2[idx1[k][0]];
            for (auto i : idx1[k]) {
                if (str2[i] != matched_char) return false;
            }
            if (idx1[k].size() == idx2[matched_char - 'a'].size()) {
                ++bimapped;
            }
        }

        return (bimapped != 26) || (str1 == str2);
    }
};


// version: 1; create time: 2019-10-20 16:54:39;
class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1.size() != str2.size()) {
            return false;
        }

        const int n = str1.size();
        std::vector<std::vector<int>> char_index1(26), char_index2(26);
        for (int i = 0; i < n; ++i) {
            char_index1[str1[i] - 'a'].push_back(i);
            char_index2[str2[i] - 'a'].push_back(i);
        }

        bool free_char = false;
        for (int i = 0; i < 26; ++i) {
            if (char_index2[i].empty()) {
                free_char = true;
            }
        }

        for (int i = 0; i < 26; ++i) {
            if (char_index2.empty()) continue;
            std::unordered_set<char> mapped;
            for (auto& loc: char_index2[i]) {
                mapped.insert(str1[loc]);
            }
            int mapped_locs = 0;
            for (auto& c: mapped) {
                mapped_locs += char_index1[c - 'a'].size();
            }
            if (mapped_locs != char_index2[i].size()) {
                return false;
            }
            if (!mapped.count(i + 'a') && !free_char) {
                return false;
            }
        }

        return true;
    }
};
