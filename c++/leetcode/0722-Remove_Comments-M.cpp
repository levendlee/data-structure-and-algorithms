// 722 Remove Comments
// https://leetcode.com/problems/remove-comments

// version: 1; create time: 2019-12-14 11:52:31;
class Solution {
public:
    enum Status { code, comment };

    void pushNonEmpty(vector<string>& preprocessed, string& buffer) {
        if (!buffer.empty()) {
            preprocessed.push_back(buffer);
        }
        buffer = "";
    }

    vector<string> removeComments(vector<string>& source) {
        vector<string> preprocessed;
        Status status = code;

        string buffer;
        for (const auto& line : source) {
            int scan_pos = 0;
            while (true) {
                if (status == code) {
                    auto pos0 = line.find("//", scan_pos);
                    auto pos1 = line.find("/*", scan_pos);
                    if (pos0 == string::npos && pos1 == string::npos) {
                        buffer += line.substr(scan_pos);
                        pushNonEmpty(preprocessed, buffer);
                        break;
                    } else if (pos0 < pos1) {
                        buffer += line.substr(scan_pos, pos0 - scan_pos);
                        pushNonEmpty(preprocessed, buffer);
                        break;
                    } else {
                        buffer += line.substr(scan_pos, pos1 - scan_pos);
                        scan_pos = pos1 + 2;
                        status = comment;
                    }
                } else {
                    auto pos2 = line.find("*/", scan_pos);
                    if (pos2 == string::npos) {
                        break;
                    } else {
                        scan_pos = pos2 + 2;
                        status = code;
                    }
                }
            }
        }
        return preprocessed;
    }
};

//

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> outputs;
        string buffer;

        auto flush_buffer = [&]() {
            if (!buffer.empty()) {
                outputs.push_back(std::move(buffer));
                buffer = "";
            }
        };

        bool block_commented = false;
        for (const auto& s : source) {
            const int n = s.size();
            int i = 0;
            while (i < n) {
                if (!block_commented) {
                    if (s[i] == '/') {
                        if (i + 1 < n && s[i + 1] == '/') {
                            flush_buffer();
                            break;
                        }
                        if (i + 1 < n && s[i + 1] == '*') {
                            block_commented = true;
                            i += 2;
                            continue;
                        }
                    }
                    buffer.push_back(s[i]);
                    ++i;
                } else {
                    if (s[i] == '*' && i + 1 < n && s[i + 1] == '/') {
                        block_commented = false;
                        i += 2;
                        continue;
                    }
                    ++i;
                }
            }
            if (!block_commented) {
                flush_buffer();
            }
        }
        return outputs;
    }
};