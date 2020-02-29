// 1108 Defanging an IP Address
// https://leetcode.com/problems/defanging-an-ip-address

// version: 1; create time: 2020-02-11 19:16:12;
class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for (const auto c : address) {
            if (c == '.') {
                res += "[.]";
            } else {
                res += c;
            }
        }
        return res;
    }
};
