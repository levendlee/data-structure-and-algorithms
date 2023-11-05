// 68 Text Justification
// https://leetcode.com/problems/text-justification

// version: 1; create time: 2019-12-14 14:55:34;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        const int n = words.size();

        vector<string> res;
        int i = 0, j = 0, width = 0;

        while (j < n) {
            width += words[j].size();

            if ((width + j - i) > maxWidth) {
                width -= words[j].size();
        Output:
                auto space = maxWidth - width;
                auto tmp = words[i];
                if ((j > i + 1) && (j != n)) {
                    auto uniform_space = space / (j - i - 1);
                    auto reminder_space = space % (j - i - 1);
                    for (int k = i + 1; k < j; ++k) {
                        tmp += std::string(uniform_space + (reminder_space-- > 0), ' ');
                        tmp += words[k];
                    }
                } else {
                    for (int k = i + 1; k < j; ++k) {
                        tmp += " ";
                        tmp += words[k];
                    }
                    tmp += std::string(maxWidth - tmp.size(), ' ');
                }
                res.push_back(std::move(tmp));

                i = j;
                width = 0;
            } else {
                ++j;
            }
        }

        if (width != 0) {
            goto Output;
        }

        return res;
    }
};

// 2023/11/04

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> results;

        const int n = words.size();
        int i = 0, j = 0;
        while (j < n) {
            int width = 0;
            int extend_width = 0;

            i = j;
            while (j < n && extend_width + words[j].size() <= maxWidth) {
                width += words[j].size();
                extend_width += words[j].size() + 1;
                ++j;
            }

            int num_spaces = maxWidth - width;
            int num_words = j - i;

            string res;
            if (num_words == 1) {
                res = words[i] + string(num_spaces, ' ');
            } else if (j == n) {
                res += words[i++];
                while (i < j) {
                    res += ' ' + words[i++];
                }
                res += string(maxWidth - res.size(), ' ');
            } else {
                int offset = 0;
                int each_spaces = num_spaces / (num_words - 1);
                int left_spaces = num_spaces % (num_words - 1);
                while (i < j) {
                    res += words[i];
                    if (++i != j) {
                        res += string(each_spaces + (left_spaces-- > 0), ' ');
                    }
                }
            }
            std::cout << res << "\n";

            results.push_back(res);
        }

        return results;
    }
};
