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