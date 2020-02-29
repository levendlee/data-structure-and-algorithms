// 388 Longest Absolute File Path
// https://leetcode.com/problems/longest-absolute-file-path

// version: 1; create time: 2020-01-05 15:44:09;
class Solution {
public:
    int lengthLongestPath(string input) {
        //stack<string> fs;
        stack<int> fs;
        int longest = 0;
        const int n = input.size();
        int idx = 0;
        while (idx < n) {
            int level = 0;
            while (idx < n && input[idx] == '\t') {
                ++idx;
                ++level;
            }
            while (fs.size() > level) {
                fs.pop();
            }
            int nex_idx = input.find('\n', idx);
            nex_idx = nex_idx == string::npos ? n : nex_idx;
            //auto cur_dir = input.substr(idx, nex_idx - idx);
            //bool is_file = cur_dir.find('.') != string::npos;
            //auto cur_path = fs.empty() ? cur_dir : fs.top() + "/" + cur_dir;
            int cur_dir_size = nex_idx - idx;
            bool is_file = input.find('.', idx) < nex_idx;
            int cur_path_size = fs.empty() ? cur_dir_size : fs.top() + 1 + cur_dir_size;
            if (is_file) {
                longest = std::max(longest, cur_path_size);
            } else {
                fs.push(cur_path_size);
            }
            if (nex_idx == string::npos) break;
            idx = nex_idx + 1;
        }
        return longest;
    }
};
