class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int order_idx[26];
        for (int i = 0; i < 26; ++i) {
            order_idx[order[i] - 'a'] = i; 
        }
        int n = words.size();
        for (int i = 0; i < n - 1; ++i) {
            bool matched = true;
            for (int j = 0; j < min(words[i].size(), words[i+1].size()); ++j) {
                int idx1 = order_idx[words[i][j] - 'a'];
                int idx2 = order_idx[words[i+1][j] - 'a'];
                if (idx1 > idx2) {
                    return false;
                } else if (idx1 < idx2) {
                    matched = false;
                    break;
                }
            }
            if (matched && words[i].size() > words[i+1].size()) {
                return false;
            }
        }
        return true;
    }
};
