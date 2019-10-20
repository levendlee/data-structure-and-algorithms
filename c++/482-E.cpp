class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int n = 0;
        for (auto& c : S) {
            n += (c != '-');
        }
        int rem = n % K;
        rem = rem ? rem : K;
        string res;
        int cnt = 0, cut = rem;
        for (auto& c : S) {
            if (c != '-') {
                res += toupper(c);
                ++cnt;
                if (cnt == cut) {
                    res += '-';
                    cnt = 0;
                    cut = K;
                }
            }
        }
        if (res.back() == '-') {
            res.pop_back();
        }
        return res;
    }
};