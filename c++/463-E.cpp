class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    constexpr int offsets[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
                    for (int k = 0; k < 4; ++k) {
                        int ii = offsets[k][0] + i;
                        int jj = offsets[k][1] + j;
                        if (ii < 0 || ii >= grid.size() || jj < 0 || jj >= grid[0].size()) {
                            ++perimeter;
                        } else {
                            perimeter += grid[ii][jj] != 1;
                        }
                    }
                }
            }
        }
        return perimeter;
    }
};