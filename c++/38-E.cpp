class Solution {
public:
    string countAndSay(int n) {
        string cur = "1";
        if (n == 1) return cur;
        for (int i = 2; i <= n; ++i) {
            string nex;
            const int m = cur.size();
            int j = 0;
            while (j < m) {
                int s = j;
                while (j + 1 < m && cur[j] == cur[j+1]) ++j;
                nex += std::to_string(j - s + 1) + cur[j];
                ++j;
            }
            cur = std::move(nex);
        }
        return cur;
    }
};