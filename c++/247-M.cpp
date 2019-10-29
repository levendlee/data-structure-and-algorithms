class Solution {
public:
    void findHelper(int n, string& prefix, string& suffix, vector<string>& res) {
        if (n == 0) {
            std::reverse(suffix.begin(), suffix.end());
            if (prefix[0] != '0')
                res.push_back(prefix + suffix);
            std::reverse(suffix.begin(), suffix.end());
            return;
        } else if (n == 1) {
            constexpr char digits[] = "018";
            std::reverse(suffix.begin(), suffix.end());
            for (int i = 0; i < 3; ++i) {
                if (prefix[0] != '0')
                    res.push_back(prefix + digits[i] + suffix);
            }
            std::reverse(suffix.begin(), suffix.end());
            return;
        } else {
            constexpr char digits0[] = "01698";
            constexpr char digits1[] = "01968";
            for (int i = 0; i < 5; ++i) {
                prefix.push_back(digits0[i]);
                suffix.push_back(digits1[i]);
                findHelper(n - 2, prefix, suffix, res);
                prefix.pop_back();
                suffix.pop_back();
            }
        }
    }

    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        string prefix, suffix;
        findHelper(n, prefix, suffix, res);
        return res;
    }
};