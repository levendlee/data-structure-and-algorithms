class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        const int m = word.size(), n = abbr.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0') return false;
                
                int k = j;
                while (k < n && isdigit(abbr[k])) ++k;
                int cnt = stoi(abbr.substr(j, k - j));
                i += cnt;
                j = k;
            } else {
                if (word[i] != abbr[j]) return false;

                ++i;
                ++j;
            }
        }
        return i == m && j == n;
    }
};
