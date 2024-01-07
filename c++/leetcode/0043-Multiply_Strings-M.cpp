// 43 Multiply Strings
// https://leetcode.com/problems/multiply-strings

// version: 1; create time: 2019-12-25 14:50:32;
// This solution is too bad. Need to rework.
class Solution {
public:
    string add(string& num1, string& num2) {
        const int n1 = num1.size();
        const int n2 = num2.size();

        string output;
        int carry = 0;
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        for (int i = 0; i < std::max(n1, n2); ++i) {
            const int d1 = i < n1 ? num1[i] - '0' : 0;
            const int d2 = i < n2 ? num2[i] - '0' : 0;
            const int res = d1 + d2 + carry;
            output.push_back((res % 10) + '0');
            carry = res / 10;
        }
        if (carry) {
            output.push_back(carry + '0');
        }
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        std::reverse(output.begin(), output.end());
        return output;
    }

    string multiply(string& num1, char digit2) {
        const int n1 = num1.size();

        string output;
        int carry = 0;
        std::reverse(num1.begin(), num1.end());
        const int d2 = digit2 - '0';
        for (int i = 0; i < n1; ++i) {
            const int d1 = i < n1 ? num1[i] - '0' : 0;
            const int res = d1 * d2 + carry;
            output.push_back((res % 10) + '0');
            carry = res / 10;
        }
        if (carry) {
            output.push_back(carry + '0');
        }
        std::reverse(num1.begin(), num1.end());
        std::reverse(output.begin(), output.end());
        return output;
    }

    string multiply(string& num1, string& num2) {
        string output;
        const int n2 = num2.size();

        std::reverse(num2.begin(), num2.end());
        for (int i = 0; i < n2; ++i) {
            auto tmp = multiply(num1, num2[i]);
            tmp += string(i, '0');
            output = add(output, tmp);
        }
        std::reverse(num2.begin(), num2.end());

        int lstrip = 0;
        while (lstrip + 1 < output.size() && output[lstrip] == '0') ++lstrip;
        return output.substr(lstrip);
    }
};

//

class Solution {
public:
    string multiply(string num1, string num2) {
        auto muln1 = [](const std::string& a, char b) -> std::string {
            std::string s;
            int carry = 0;
            for (int i = 0; i < a.size(); ++i) {
                int num = (a[i] - '0') * (b - '0') + carry;
                s += ('0' + num % 10);
                carry = num / 10;
            }
            if (carry) {
                s += ('0' + carry);
            }
            return s;
        };
        auto addnn = [](const std::string& a, const std::string& b) -> std::string {
            std::string s;
            const int m = a.size(), n = b.size();
            int i = 0, carry = 0;
            while (i < max(m, n)) {
                int sum;
                if (i < m && i < n) {
                    sum = (a[i] - '0') + (b[i] - '0');
                } else if (i < m) {
                    sum = (a[i] - '0');
                } else {
                    sum = (b[i] - '0');
                }
                sum += carry;
                s += '0' + sum % 10;
                carry = sum / 10;
                ++i;
            }
            if (carry) {
                s += '0' + carry;
            }
            return s;
        };
        auto mulnn = [&](const std::string& a, const std::string& b) -> std::string {
            const int m = a.size(), n = b.size();
            string s;
            for (int i = 0; i < n; ++i) {
                auto temp = muln1(a, b[i]);
                temp = std::string(i, '0') + temp;
                s = addnn(s, temp);
            }
            int valid_size = s.size();
            while (valid_size > 1 && s[valid_size - 1] == '0') --valid_size;
            s.resize(valid_size);
            return s;
        };
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        auto res = mulnn(num1, num2);
        reverse(res.begin(), res.end());
        return res;
    }
};