class Solution {
public:
    bool rotateMatch(const char l, const char r) {
        return (l == r) && (l == '0' || l == '1' || l == '8') || (l == '6' && r == '9') || (l == '9' && r == '6');
    }

    bool isStrobogrammatic(string num) {
        const int n = num.size();
        int i = 0, j = n - 1;
        while (i < j) {
            if (!rotateMatch(num[i++], num[j--])) return false;
        }
        if ((i == j) && !rotateMatch(num[i], num[i])) return false;
        return true;
    }
};