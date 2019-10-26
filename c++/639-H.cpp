class Solution {
public:
    int numDecodings(string s) {
        const int n = s.size();
        const int64_t mode = pow(10, 9) + 7;

        int64_t pre_ways = 1, cur_ways = 1, nex_ways = 1;
        for (int i = 0; i < n; ++i) {
            // one digit
            if (s[i] == '*') {
                nex_ways = cur_ways * 9;
            } else if (s[i] != '0') {
                nex_ways = cur_ways;
            } else {
                nex_ways = 0;
            }

            // two digits
            if (i > 0) {
                if (s[i-1] == '1') {
                    if (s[i] == '*') {
                        nex_ways += pre_ways * 9;
                    } else {
                        nex_ways += pre_ways;
                    }
                } else if (s[i-1] == '2') {
                    if (s[i] == '*') {
                        nex_ways += pre_ways * 6;
                    } else if (s[i] <= '6') {
                        nex_ways += pre_ways;
                    }
                } else if (s[i-1] == '*') {
                    if (s[i] == '*') {
                        nex_ways += pre_ways * 15;
                    } else if (s[i] <= '6') {
                        nex_ways += pre_ways * 2;
                    } else {
                        nex_ways += pre_ways;
                    }
                }
            }
            pre_ways = cur_ways;
            cur_ways = nex_ways % mode;
        }

        return cur_ways;
    }
};