class Solution {
public:
    int candy(vector<int>& ratings) {
        const int n = ratings.size();

        vector<int> inc_seq_vec(n, 0);
        int inc_seq = 1;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && ratings[i - 1] < ratings[i]) {
                ++inc_seq;
            } else {
                inc_seq = 1;
            }
            inc_seq_vec[i] = inc_seq;
        }

        int sum = 0;
        int des_seq = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (i < n - 1 && ratings[i + 1] < ratings[i]) {
                ++des_seq;
            } else {
                des_seq = 1;
            }
            sum += max(inc_seq_vec[i], des_seq);
        }

        return sum;
    }
};
