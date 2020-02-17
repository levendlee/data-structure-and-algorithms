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