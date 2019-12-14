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