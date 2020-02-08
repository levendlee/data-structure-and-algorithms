class Solution {
public:
    string toGoatLatin(string s) {
        string res;
        int cnt = 0;
        int n = s.size();
        int i = 0;

        const auto is_vowel = [](const char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        while (i < n) {
            if (!res.empty()) res += ' ';
            int j = s.find(' ', i);
            j = j == string::npos ? n : j;
            auto word = s.substr(i, j - i);
            if (is_vowel(word[0]) || is_vowel(tolower(word[0]))) {
                res += word + "ma" + string(++cnt, 'a');
            } else {
                res += word.substr(1) + word[0] + "ma" + string(++cnt, 'a');
            }
            i = j;
            while (i < n && s[i] == ' ') ++i;
        }

        return res;
    }
};