// 1048 Longest String Chain
// https://leetcode.com/problems/longest-string-chain

// version: 1; create time: 2019-12-10 20:18:45;
class Solution {
public:
    bool isPred(const std::string& a, const std::string& b) {
        if (a.size() + 1 != b.size()) {
            return false;
        }
        int i = 0, j = 0;
        bool added = false;
        while (i < a.size()) {
            if (a[i] == b[j]) {
                ++i;
                ++j;
            } else {
                if (added) {
                    return false;
                } else {
                    added = true;
                }
                ++j;
            }
        }
        return true;
    }

    int longestStrChain(vector<string>& words) {
        const int n = words.size();
        vector<vector<int>> preds(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPred(words[i], words[j])) {
                    preds[j].push_back(i);
                }
                if (isPred(words[j], words[i])) {
                    preds[i].push_back(j);
                }
            }
        }

        vector<int> lens(n, 1);
        bool updated;
        do {
            updated = false;
            for (int i = 0; i < n; ++i) {
                for (const auto& p : preds[i]) {
                    if (lens[p] < (lens[i] + 1)) {
                        lens[p] = lens[i] + 1;
                        updated = true;
                    }
                }
            }
        } while (updated);

        return *std::max_element(lens.begin(), lens.end());
    }
};
