class Solution {
public:
    int numDecodings(string s) {
        const int n = s.size();
        int dp0 = 1, dp1 = 1;
        for (int i = 0; i < n; ++i) {
            int ndp = 0;
            int digit = s[i] - '0';
            if (digit == 0) {
                if (i == 0 || (s[i-1] != '1' && s[i-1] != '2')) return 0;
                ndp = dp0;
            } else if (digit <= 6) {
                if (i == 0 || (s[i-1] != '1' && s[i-1] != '2')) {
                    ndp = dp1;
                } else {
                    ndp = dp0 + dp1;
                }
            } else {
                if (i == 0 || (s[i-1] != '1')) {
                    ndp = dp1;
                } else {
                    ndp = dp0 + dp1;
                }
            }
            dp0 = dp1;
            dp1 = ndp;
        }
        return dp1;
    }
};