class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        const int n = grid.size();

        int res = 0;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                bool mismatch = false;
                for (int i = 0; i < n; ++i) {
                    if (grid[row][i] != grid[i][col]) {
                        mismatch = true;
                        break;
                    }
                }
                res += !mismatch;
            }
        }

        return res;
    }
};
