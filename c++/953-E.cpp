class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int order_index[26];
        for (int i = 0; i < 26; ++i) {
            const auto c = order[i];
            order_index[c - 'a'] = i;
        }
        const int n = words.size();
        const auto is_sorted = [&](const string& w0, const string& w1) {
            const int m = std::min(w0.size(), w1.size());
            for (int j = 0; j < m; ++j) {
                const int idx0 = w0[j] - 'a';
                const int idx1 = w1[j] - 'a';
                if (order_index[idx0] > order_index[idx1]) {
                    return false;
                } else if (order_index[idx0] < order_index[idx1]) {
                    return true;
                }
            }
            return w0.size() <= w1.size();
        };

        if (n <= 1) return true;
        for (int i = 1; i < n; ++i) {
            if (!is_sorted(words[i-1], words[i])) {
                return false;
            }
        }
        return true;
    }
};