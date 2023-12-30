class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> cur_layer(1);
        cur_layer[0] = poured;
        for (int r = 1; r <= query_row; ++r) {
            vector<double> nex_layer(r + 1);
            for (int c = 0; c < r; ++c) {
                double overflow = (cur_layer[c] - 1.0) / 2.0;
                if (overflow > 0.0) {
                    nex_layer[c] += overflow;
                    nex_layer[c+1] += overflow;
                }
            }
            cur_layer = nex_layer;
        }
        return min(cur_layer[query_glass], 1.0);
    }
};