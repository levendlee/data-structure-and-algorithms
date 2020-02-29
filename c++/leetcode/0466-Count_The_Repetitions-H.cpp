// 466 Count The Repetitions
// https://leetcode.com/problems/count-the-repetitions

// version: 1; create time: 2020-01-29 21:26:13;
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        // starting from index i, matching s1 with s2,
        // when s2 is matched, s1 is shifted with match_count[i] * s1.size() + match_shift[i]
        vector<int> match_shift(s1.size(), 0);
        vector<int> match_count(s1.size(), 0);
        for (int i = 0; i < s1.size(); ++i) {
            int j = i, k = 0, pre_k = -1;
            while (k < s2.size()) {
                if (s1[j] == s2[k]) {
                    ++j; ++k;
                } else {
                    ++j;
                }
                if (j == s1.size()) {
                    if (k == pre_k) {
                        return 0;
                    }
                    pre_k = k;
                    j = 0;
                    ++match_count[i];
                }
            }
            match_shift[i] = j;
        }

        int matched1 = 0;
        int matched2 = 0;
        /*
        bool detect_period = true;
        vector<int> period_matched1(s1.size(), -1);
        vector<int> period_matched2(s1.size(), -1);
        */
        int i = 0;
        while (true)
        {
            matched1 += match_count[i];
            i = match_shift[i];
            if (matched1 >= n1) break;
            matched2 += 1;

            /*
            if (detect_period && period_matched1[i] != -1) {
                // we found a period
                int matched1_in_period = matched1 - period_matched1[i];
                int matched2_in_period = matched2 - period_matched2[i];
                int periods = (n1 - matched1) / matched1_in_period - 1;
                matched1 += matched1_in_period * periods;
                matched2 += matched2_in_period * periods;
                period_matched1[i] = -1;
                detect_period = false;
            } else {
                period_matched1[i] = matched1;
                period_matched2[i] = matched2;
            }
            */
        }
        if (i == 0) matched2 += 1;
        return matched2 / n2;
    }
};
