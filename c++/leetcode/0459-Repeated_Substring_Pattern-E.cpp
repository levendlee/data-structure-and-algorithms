// 459 Repeated Substring Pattern
// https://leetcode.com/problems/repeated-substring-pattern

// version: 1; create time: 2020-01-18 20:40:00;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        /*
        const int n = s.size();
        for (int i = 1; i <= n / 2; ++i) {
            if (n % i) continue;
            bool success = true;
            const string substr = s.substr(0, i);
            for (int j = i; j + i <= n; j += i) {
                if (s.substr(j, i) != substr) {
                    success = false;
                    break;
                }
            }
            if (success) return true;
        }
        return false;
        */
        if (s.size() <= 1) return false;
        string tmp = s + s;
        tmp = tmp.substr(1, tmp.size() - 2);
        return tmp.find(s) != string::npos;
    }
};
