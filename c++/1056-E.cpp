class Solution {
public:
    bool confusingNumber(int N) {
        constexpr bool rotatable[10] = {1,1,0,0,0,0,1,0,1,1};

        std::string digits = std::to_string(N);
        const int n = digits.size();
        int i = 0, j = n - 1;

        bool confusing = true;
        while (i <= j) {
            const char c0 = digits[i];
            const char c1 = digits[j];
            if (!rotatable[c0 - '0'] || !rotatable[c1 - '0']) {
                return false;
            }
            if (c0 == '6' && c1 == '9' || c0 == '9' && c1 == '6') {
                // nothing
            } else if (c0 != c1 || c0 == '6' || c0 == '9') {
                confusing = false;
            }
            ++i;
            --j;
        }
        return !confusing;
    }
};