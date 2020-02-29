// 267 Palindrome Permutation II
// https://leetcode.com/problems/palindrome-permutation-ii

// version: 1; create time: 2020-01-26 14:32:20;
class Solution {
public:
    void dfs(vector<int>& counter, const int n, string& str, vector<string>& res) {
        if (str.size() == n) {
            res.push_back(str);
            return;
        }
        for (int i = 0; i < 256; ++i) {
            const char c = i;
            if (counter[i] >= 2) {
                auto tmp = c + str + c;
                counter[i] -= 2;
                dfs(counter, n, tmp, res);
                counter[i] += 2;
            }
        }
    }

    vector<string> generatePalindromes(string s) {
        vector<int> counter(256, 0);
        for (const auto& c : s) {
            ++counter[c];
        }

        int mid = -1;
        for (int i = 0; i < 256; ++i) {
            if (counter[i] % 2) {
                if (mid != -1) {
                    return {};
                }
                mid = i;
            }
        }

        vector<string> res;
        string str;
        if (mid != -1) {
            str += char(mid);
        }
        dfs(counter, s.size(), str, res);
        return res;
    }
};
