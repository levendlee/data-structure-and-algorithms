class Solution {
public:
    char findTheDifference(string s, string t) {
        int counter[26] = {0};
        for (auto c : s) {
            ++counter[c - 'a'];
        }
        for (auto c : t) {
            if (--counter[c - 'a'] < 0) {
                return c;
            }
        }
        return ' ';
    }
};