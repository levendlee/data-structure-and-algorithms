// 986 Interval List Intersections
// https://leetcode.com/problems/interval-list-intersections

// version: 1; create time: 2020-01-25 16:45:20;
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

//

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        const int n1 = firstList.size(), n2 = secondList.size();

        vector<vector<int>> res;
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            int min0 = firstList[i][0], max0 = firstList[i][1];
            int min1 = secondList[j][0], max1 = secondList[j][1];
            if (max0 < min1) {
                ++i;
            } else if (max1 < min0) {
                ++j;
            } else {
                int intersect_min = max(min0, min1);
                int intersect_max = min(max0, max1);
                res.push_back({intersect_min, intersect_max});

                if (max0 < max1) {
                    ++i;
                } else if (max1 < max0) {
                    ++j;
                } else {
                    ++i;
                    ++j;
                }
            }
        }

        return res;
    }
};
