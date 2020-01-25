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