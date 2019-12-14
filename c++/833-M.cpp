class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        const int n = indexes.size();
        if (n == 0) return S;

        vector<int> rank(n);
        std::iota(rank.begin(), rank.end(), 0);
        std::sort(rank.begin(), rank.end(),
                 [&](const int& l, const int& r) { return indexes[l] < indexes[r]; });

        int spos = 0;
        string res = "";
        for (int i = 0; i < n; ++i) {
            int k = rank[i];

            int rpos = indexes[k];
            res += S.substr(spos, rpos - spos);  // Append substrings between replacements
            spos = rpos;

            int nn = sources[k].size();
            if (S.substr(rpos, nn) == sources[k]) {
                res += targets[k];
                spos += nn;
            }
        }
        res += S.substr(spos);
        return res;
    }
};