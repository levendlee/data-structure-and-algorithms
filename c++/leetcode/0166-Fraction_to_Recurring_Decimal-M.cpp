// 166 Fraction to Recurring Decimal
// https://leetcode.com/problems/fraction-to-recurring-decimal

// version: 1; create time: 2020-02-01 14:42:49;
class Solution {
public:
    string fractionToDecimal(long n, long d) {
        string res = std::to_string(abs(n / d));
        if (n > 0 && d < 0 || n < 0 && d > 0) res = '-' + res;
        n = abs(n); d = abs(d);
        if (n % d == 0) return res;
        res += '.';
        n = (n % d) * 10;

        unordered_map<int, int> n_idx;
        while (n) {
            if (n_idx.count(n)) {
                const auto idx = n_idx[n];
                return res.substr(0, idx) + '(' + res.substr(idx) + ')';
            }
            n_idx[n] = res.size();
            res += (n / d) + '0';
            n = (n % d) * 10;
        }

        return res;
    }
};
