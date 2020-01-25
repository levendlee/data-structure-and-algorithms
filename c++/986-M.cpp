class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;

        const int m = A.size();
        const int n = B.size();
        if (m == 0 || n == 0) return res;


        int i = 0, j = 0;
        while (i < m && j < n) {
            if (A[i][1] < B[j][0]) {
                ++i;
            } else if (B[j][1] < A[i][0]) {
                ++j;
            } else {
                res.push_back({std::max(A[i][0], B[j][0]), std::min(A[i][1], B[j][1])});
                if (A[i][1] < B[j][1]) {
                    ++i;
                } else if (A[i][1] > B[j][1]) {
                    ++j;
                } else {
                    ++i; ++j;
                }
            }
        }

        return res;
    }
};