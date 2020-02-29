// 616 Add Bold Tag in String
// https://leetcode.com/problems/add-bold-tag-in-string

// version: 1; create time: 2020-02-08 16:56:27;
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        const int n = s.size();
        vector<bool> tags(n, false);
        for (const auto& str : dict) {
            int i = 0;
            while (true) {
                i = s.find(str, i);
                if (i == string::npos) break;
                for (int k = 0; k < str.size(); ++k) tags[i + k] = true;
                ++i;
            }
        }
        string res;
        int i = 0;
        while (i < n) {
            if (!tags[i]) {
                res += s[i++];
            } else {
                int j = i;
                while (j < n && tags[j]) ++j;
                res += "<b>" + s.substr(i, j - i) + "</b>";
                i = j;
            }
        }
        return res;
    }
};
