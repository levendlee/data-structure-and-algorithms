class Solution {
public:
    string toLowerCase(string str) {
        string res;
        constexpr int offset = 'a' - 'A';
        for (const auto c : str) {
            res += (c >= 'A' && c <= 'Z') ? c + offset : c;
        }
        return res;
    }
};