// 65 Valid Number
// https://leetcode.com/problems/valid-number

// version: 1; create time: 2020-02-06 21:40:48;
class Solution {
public:
    bool isNumber(string s) {
        const int n = s.size();
        int i = 0, j = n - 1;
        while (i < n && s[i] == ' ') ++i;
        while (j >= 0 && s[j] == ' ') --j;

        bool sign_set = false;
        bool int_num_set = false;
        bool dec_set = false;
        bool dec_num_set = false;
        bool exp_set = false;
        bool exp_num_set = false;

        while (i <= j) {
            if (s[i] == '+' || s[i] == '-') {
                if (sign_set) return false;
                sign_set = true;
            } else if (s[i] == '.') {
                if (dec_set) return false;
                dec_set = true;
                sign_set = true;
            } else if (s[i] == 'e') {
                if (!int_num_set && !dec_num_set || exp_set) return false;
                exp_set = true;
                sign_set = false;
                dec_set = true;
            } else if (isdigit(s[i])) {
                if (exp_set) {
                    exp_num_set = true;
                } else if (dec_set) {
                    dec_num_set = true;
                } else {
                    int_num_set = true;
                }
                sign_set = true;
            } else {
                return false;
            }
            ++i;
        }
        return !(!int_num_set && !dec_num_set || exp_set && !exp_num_set);
    }
};

//

class Solution {
public:
    bool isNumber(string s) {
        const int n = s.size();

        auto read_int = [&](int& i) {
            int j = i;
            while (i < n && isdigit(s[i])) {
                ++i;
            }
            return j != i;
        };

        bool int0 = false, int1 = false, int2 = false, dot = false, e = false, sign0 = false, sign1 = false;

        int i = 0;

        if (s[i] == '+' || s[i] == '-') { sign0 = true; ++i; }

        int0 = read_int(i);

        if (i == n) goto resolve;
        if (s[i] == '.') { dot = true; ++i; }

        int1 = read_int(i);

        if (i == n) goto resolve;
        if (s[i] == 'e' || s[i] == 'E') { e = true; ++i; }

        if (i == n) goto resolve;
        if (s[i] == '+' || s[i] == '-') { sign1 = true; ++i; }

        int2 = read_int(i);

        if (i != n) return false;

        resolve:
        return (int0 || dot && int1) && (!e && !int2 || e && int2) && !(sign1 && !int2);

    }
};
