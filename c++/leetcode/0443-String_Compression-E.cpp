// 443 String Compression
// https://leetcode.com/problems/string-compression

// version: 1; create time: 2020-02-01 15:27:52;
class Solution {
public:
    int compress(vector<char>& chars) {
        const int n = chars.size();
        int i = 0, j = 0;
        while (j < n) {
            int s = j;
            while (j + 1 < n && chars[j + 1] == chars[j]) ++j;
            int cnt = j - s + 1;
            chars[i++] = chars[j];
            ++j;
            if (cnt == 1) continue;

            int ds = i;
            while (cnt) {
                chars[i++] = (cnt % 10) + '0';
                cnt = cnt / 10;
            }
            std::reverse(chars.begin() + ds, chars.begin() + i);
        }
        return i;
    }
};

