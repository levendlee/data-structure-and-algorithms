// 168 Excel Sheet Column Title
// https://leetcode.com/problems/excel-sheet-column-title

// version: 1; create time: 2020-01-29 21:26:13;
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n) {
            res.push_back((n - 1) % 26 + 'A');
            n = (n - 1) / 26;
        };
        std::reverse(res.begin(), res.end());
        return res;
    }
};
