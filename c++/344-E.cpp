class Solution {
public:
    void reverseString(vector<char>& s) {
        const int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            std::swap(s[i++], s[j--]);
        }
    }
};