// 158 Read N Characters Given Read4 II - Call multiple times
// https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times

// version: 1; create time: 2019-10-23 22:30:09;
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    bool file_end_;
    std::queue<char> buffer_;
    
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    Solution() : file_end_(false) {}
    
    int read(char *buf, int n) {
        if (file_end_ && buffer_.empty()) return 0;
        
        int buffered = buffer_.size();
        for (int i = 0; i < std::min(n, buffered); ++i) {
            *buf = buffer_.front();
            ++buf;
            buffer_.pop();
        }
        if (buffered >= n) {
            return n;
        }
        
        int remaining = n - buffered;
        int read4size = (remaining / 4) * 4;
        for (int i = 0; i < read4size; i += 4) {
            auto success = read4(buf);
            buf += 4;
            if (success != 4) {
                file_end_ = true;
                return buffered + i + success;
            }
        }
        if ((buffered + read4size) == n) {
            return n;
        }
        
        char temp[4];
        int success = read4(temp);
        file_end_ = success != 4;
        for (int i = 0; i < success; ++i) {
            buffer_.push(temp[i]);
        }
        
        return buffered + read4size + read(buf, n - buffered - read4size);
    }
    
};
