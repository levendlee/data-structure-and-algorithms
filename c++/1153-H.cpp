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