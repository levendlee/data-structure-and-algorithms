class Solution {
public:
    int lengthOfLastWord(string s) {
        int last_length = 0;
        int length = 0;
        for (char c : s) {
            if (c == ' ') {
                last_length = length == 0 ? last_length : length;
                length = 0;
            } else {
                ++length;
            }
        }

        return length == 0 ? last_length : length;
    }
};
