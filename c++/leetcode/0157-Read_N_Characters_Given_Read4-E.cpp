// 157 Read N Characters Given Read4
// https://leetcode.com/problems/read-n-characters-given-read4

// version: 1; create time: 2020-02-08 00:05:28;
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int nchar = 0;
        char tmp[4];
        while (nchar < n) {
            int rc;
            if (n - nchar >= 4) {
                rc = read4(buf);
            } else {
                rc = read4(tmp);
                rc = std::min(rc, n - nchar);
                for (int k = 0; k < rc; ++k) {
                    buf[k] = tmp[k];
                }
            }
            nchar += rc;
            buf += rc;
            if (rc != 4) return nchar;
        }
        return nchar;
    }
};
