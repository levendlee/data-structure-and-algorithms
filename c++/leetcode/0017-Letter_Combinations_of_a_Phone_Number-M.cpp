// 17 Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number

// version: 1; create time: 2020-01-25 15:41:11;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> dict = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> tmp = {""};
        for (const char d : digits) {
            vector<string> nex;
            for (const char c : dict[d - '2']) {
                for (const auto& prefix : tmp) {
                    nex.push_back(prefix + c);
                }
            }
            tmp = std::move(nex);
        }

        return tmp;
    }
};
