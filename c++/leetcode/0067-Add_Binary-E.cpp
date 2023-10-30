// 67 Add Binary
// https://leetcode.com/problems/add-binary

// version: 1; create time: 2020-01-15 18:52:13;
class Solution {
public:
    string addBinary(string a, string b) {
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        const int m = a.size();
        const int n = b.size();
        int carry = 0;
        string res;
        for (int i = 0; i < std::max(m, n); ++i) {
            const int lhs = i < m ? (a[i] - '0') : 0;
            const int rhs = i < n ? (b[i] - '0') : 0;
            int sum = carry + lhs + rhs;
            res.push_back((sum & 0x1) + '0');
            carry = sum / 2;
        }
        if (carry) res.push_back('1');
        std::reverse(res.begin(), res.end());
        return res;
    }
};

// 2023/10/29

class Solution {
public:
    string addBinary(string a, string b) {
        const int na = a.size(), nb = b.size();

        string res;
        int ia = na - 1, ib = nb - 1, carry = 0;
        while (ia >= 0 || ib >= 0) {
            int ca = ia >= 0 ? a[ia] - '0' : 0;
            int cb = ib >= 0 ? b[ib] - '0' : 0;
            int cr = ca + cb + carry;
            res.push_back((cr % 2) + '0');
            carry = cr / 2;
            --ia; --ib;
        }
        if (carry != 0) {
            res.push_back(carry + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
