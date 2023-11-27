class Solution {
public:
    int minInsertions(string s) {
        int missing_right = 0;
        int insertions = 0;
        for (char c : s) {
            if (c == '(') {
                if (missing_right & 0x1) {
                    // insert ')'
                    --missing_right;
                    ++insertions;
                }
                missing_right += 2;
            } else {
                if (missing_right == 0) {
                    // insert '('
                    missing_right += 2;
                    ++insertions;
                }
                --missing_right;
            }
        }
        insertions += missing_right;
        return insertions;
    }
};
