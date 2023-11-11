class Solution {
public:
    string decodeString(string s) {
        stack<int> repeats;
        stack<string> strings;
        auto ensure_stack = [&]() {
            if (strings.empty()) {
                repeats.push(1);
                strings.push("");
            }
        };
        const int n = s.size();
        int i = 0, j = 0;
        while (j < n) {
            i = j;
            if (isdigit(s[j])) {
                while (j < n && isdigit(s[j])) ++j;
                int num = stoi(s.substr(i, j - i));
                repeats.push(num);
                strings.push("");
            } else if (isalpha(s[j])) {
                while (j < n && isalpha(s[j])) ++j;
                auto str = s.substr(i, j - i);
                ensure_stack();
                strings.top() += str;
            } else if (s[j] == ']') {
                auto str = strings.top();
                strings.pop();
                auto repeat = repeats.top();
                repeats.pop();
                string repeated_string;
                for (int k = 0; k < repeat; ++k) {
                    repeated_string += str;
                }
                ensure_stack();
                strings.top() += repeated_string;
                ++j;
            } else {
                ++j;
            }
        }
        return strings.top();
    }
};
