class Solution {
public:
    int numSplits(string s) {
        int hash[26] = {0};
        const int n = s.size();
        vector<int> cnts(n);
        int uniq = 0;
        for (int i = 0; i < n; ++i) {
            if (hash[s[i] - 'a'] == 0) {
                uniq++;
            }
            hash[s[i] - 'a']++;
            cnts[i] = uniq;
        }
        int res = 0;
        fill(hash, hash + 26, 0);
        uniq = 0;
        for (int i = n - 1; i >= 1; --i) {
            if (hash[s[i] - 'a'] == 0) {
                uniq++;
            }
            hash[s[i] - 'a']++;
            if (cnts[i-1] == uniq) {
                res++;
            }
        }
        return res;
    }
};
