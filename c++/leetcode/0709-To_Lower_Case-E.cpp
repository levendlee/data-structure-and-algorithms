// 709 To Lower Case
// https://leetcode.com/problems/to-lower-case

// version: 1; create time: 2020-02-01 20:26:33;
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
