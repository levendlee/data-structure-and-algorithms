class Solution {
public:
    string removeDuplicates(string s, int k) {
        if (s.empty()) return 0;

        stack<pair<char, int>> stk;
        for (const auto& c : s) {
            if (stk.empty() || stk.top().first != c) {
                stk.push({c, 1});
            } else {
                ++stk.top().second;
                if (stk.top().second == k) {
                    stk.pop();
                }
            }
        }

        string res;
        while (!stk.empty()) {
            auto p = stk.top(); stk.pop();
            res = string(p.second, p.first) + res;
        }
        return res;
    }
};