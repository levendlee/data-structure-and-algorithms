class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        constexpr int offsets[8][2] = {
            {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, 
            {-2, -1}, {-2, 1}, {2, -1}, {2, 1}
        };

        vector<vector<double>> prob(n, vector<double>(n, 0));
        prob[row][column] = 1.0;

        for (int l = 0; l < k; ++l) {
            vector<vector<double>> next_prob(n, vector<double>(n, 0));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (prob[i][j] == 0.0) continue;
                    for (auto ij : offsets) {
                        int ii = i + ij[0];
                        int jj = j + ij[1];
                        if (ii < 0 || ii >= n || jj < 0 || jj >= n) continue;
                        next_prob[ii][jj] += prob[i][j] * 0.125;
                    }
                }
            }
            prob = move(next_prob);
        }

        double sum = 0.0;
        for (int i = 0; i < n; ++i) {
            sum += accumulate(prob[i].begin(), prob[i].end(), 0.0);
        }
        return sum;
    }
};