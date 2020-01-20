class Solution {
private:
    int m_;
    int n_;

public:
    void dfs(vector<vector<int>>& image, int i, int j, int oldColor, int newColor) {
        constexpr int offsets[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (int k = 0; k < 4; ++k) {
            const int ii = i + offsets[k][0];
            const int jj = j + offsets[k][1];
            if (ii >= 0 && ii < m_ && jj >= 0 && jj < n_ && image[ii][jj] == oldColor) {
                image[ii][jj] = newColor;
                dfs(image, ii, jj, oldColor, newColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m_ = image.size();
        if (m_ == 0) return image;
        n_ = image[0].size();
        if (n_ == 0) return image;
        if (image[sr][sc] == newColor) return image;

        dfs(image, sr, sc, image[sr][sc], newColor);
        image[sr][sc] = newColor;
        return image;
    }
};