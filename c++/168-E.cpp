class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n) {
            res.push_back((n - 1) % 26 + 'A');
            n = (n - 1) / 26;
        };
        std::reverse(res.begin(), res.end());
        return res;
    }
};