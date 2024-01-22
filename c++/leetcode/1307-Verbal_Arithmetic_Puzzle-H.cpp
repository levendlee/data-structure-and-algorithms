class Solution {
public:
    bool isSolvable(vector<string>& words, string result) {
        int coeffs[26] = {0};
        bool leading[26] = {false};
        for (const auto& s : words) {
            const int n = s.size();
            int base = 1;
            for (int i = n - 1; i >= 0; --i) {
                coeffs[s[i] - 'A'] += base;
                base *= 10;
            }
            if (s.size() > 1) {
                leading[s[0] - 'A'] = true;
            }
        }
        {
            const int n = result.size();
            int base = 1;
            for (int i = n - 1; i >= 0; --i) {
                coeffs[result[i] - 'A'] -= base;
                base *= 10;
            }
            if (result.size() > 1) {
                leading[result[0] - 'A'] = true;
            }
        }

        function<bool(int,int, int)> backtracking;
        backtracking = [&](int index, int mask, int target) {
            for (int i = index; i <= 26; ++i) {
                if (i == 26 || coeffs[i] != 0) {
                    index = i;
                    break;
                }
            }
            if (index == 26) {
                return target == 0;
            }
            for (int i = 0; i <= 9; ++i) {
                if (i == 0 && leading[index]) continue;
                if (!(mask & (1 << i))) {
                    if (backtracking(index + 1, mask | (1 << i), target + i * coeffs[index])) {
                        return true;
                    }
                }
            }
            return false;
        };

        return backtracking(0, 0, 0);
    }
};