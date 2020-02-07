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