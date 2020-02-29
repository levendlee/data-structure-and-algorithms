// 93 Restore IP Addresses
// https://leetcode.com/problems/restore-ip-addresses

// version: 1; create time: 2020-02-11 18:07:01;
class Solution {
private:
    void search(vector<string>& res, const string& cur, const string& s, int i, int parts) {
        if (i == s.size() && parts == 4) {
            res.push_back(cur);
        } else if (i == s.size() || parts >= 4) {
            return;
        } else {
            const int n = s.size();
            for (int j = i; j < std::min(n, i + 3); ++j) {
                auto num = s.substr(i, j - i + 1);
                if (stoi(num) > 255) continue;
                if (num.size() > 1 && num[0] == '0') continue;
                search(res, cur.empty() ? num : (cur + '.' + num), s, j + 1, parts + 1);
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string cur;
        search(res, cur, s, 0, 0);
        return res;
    }
};
