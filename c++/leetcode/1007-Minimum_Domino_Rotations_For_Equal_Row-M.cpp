// 1007 Minimum Domino Rotations For Equal Row
// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row

// version: 1; create time: 2020-02-17 21:43:04;
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        const int n = A.size();
        int cnt[6] = {0};
        for (int i = 0; i < n; ++i) {
            ++cnt[A[i] - 1];
            if (A[i] != B[i]) {
                ++cnt[B[i] - 1];
            }
        }
        int target = -1;
        for (int i = 0; i < 6; ++i) {
            if (cnt[i] == n) {
                target = i + 1; break;
            }
        }
        if (target == -1) return -1;
        int swap0 = 0, swap1 = 0;
        for (const auto& a : A) swap0 += a != target;
        for (const auto& b : B) swap1 += b != target;
        return min(swap0, swap1);
    }
};
