class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        int size = 0;
        while (true) {
            for (const auto& s : strs) {
                if (s.size() <= size) goto resolve;
                if (s[size] != strs[0][size]) goto resolve;
            }
            ++size;
        }

        resolve:
        return strs[0].substr(0, size);
    }
};