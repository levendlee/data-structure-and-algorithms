class Solution {
public:
    int minSwaps(string s) {
        const int n = s.size();

        int swaps = 0;
        int stk = 0;
        int i = 0, j = s.size() - 1;
        while (i < n) {
            if (s[i] == '[') {
                ++stk;
            } else {
                --stk;
            }
            if (stk == -1) {
                while (j >= 0 && s[j] == '[') --j;
                swap(s[i], s[j]);
                --j;
                ++swaps;
                stk += 2;
            }
            ++i;
        }
        return swaps;
    }
};