class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        const int n1 = str1.size(), n2 = str2.size();

        int d = 1, gcd = 0;
        while (d <= n1 && d <= n2) {
            if (str1[d - 1] != str2[d - 1]) {
                break;
            }
            if (n1 % d || n2 % d) {
                ++d;
                continue;
            }
            auto base = str1.substr(0, d);
            for (int i = 0; i + d <= n1; i += d) {
                if (str1.substr(i, d) != base) goto resolve;
            }
            for (int i = 0; i + d <= n2; i += d) {
                if (str2.substr(i, d) != base) goto resolve;
            }
            gcd = d;

            resolve:
            ++d;
        }
        
        return str1.substr(0, gcd);
    }
};

//

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2) == (str2 + str1) ?  str1.substr(0, gcd(str1.size(), str2.size())) : "";
    }
};
