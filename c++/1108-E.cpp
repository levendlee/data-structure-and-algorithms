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