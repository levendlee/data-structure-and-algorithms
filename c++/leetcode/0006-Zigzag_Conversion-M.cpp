class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string res;
        const int n = s.size();
        for (int i = 0; i < numRows; ++i) {
            int d1 = max(2 * i, 0);
            int d0 = max(2 * (numRows - i - 1), 0);

            int idx = i;
            if (idx < n) {
                res += s[idx];
            }
            while (true) {
                idx += d0;
                if (idx >= n) break;
                if (d0 != 0)
                    res += s[idx];

                idx += d1;
                if (idx >= n) break;
                if (d1 != 0)
                    res += s[idx];
            }
        }
        return res;
    }
};
