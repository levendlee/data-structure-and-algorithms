// 593 Valid Square
// https://leetcode.com/problems/valid-square

// version: 1; create time: 2020-01-26 22:16:04;
class Solution {
public:
    bool isPerpendicular(const vector<int>& p0, const vector<int>& p1, const vector<int>& p2) {
       return ((p0[0] - p1[0]) * (p1[0] - p2[0]) + (p0[1] - p1[1]) * (p1[1] - p2[1])) == 0;
    }

    int calcLen(const vector<int>& p0, const vector<int>& p1) {
        auto x = p0[0] - p1[0];
        auto y = p0[1] - p1[1];
        return x * x + y * y;
    }

    bool checkSquare(vector<int>& perm, vector<vector<int>>& points) {
        const auto vec = [&](const int i) -> vector<int>& { return points[perm[i]]; };
        for (int i = 0; i < 4; ++i) {
            int j = (i + 1) % 4;
            int k = (j + 1) % 4;
            if (!isPerpendicular(vec(i), vec(j), vec(k))) {
                return false;
            }
            const int s1 = calcLen(vec(i), vec(j));
            const int s2 = calcLen(vec(j), vec(k));
            if (s1 != s2 || s1 == 0) {
                return false;
            }
        }
        return true;
    }

    bool checkPermutation(vector<int>& perm, vector<vector<int>>& points) {
        if (perm.size() == 4) {
            return checkSquare(perm, points);
        }
        for (int i = 0; i < 4; ++i) {
            if (std::find(perm.begin(), perm.end(), i) == perm.end()) {
                perm.push_back(i);
                if (checkPermutation(perm, points)) {
                    return true;
                }
                perm.pop_back();
            }
        }
        return false;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        vector<int> perm;
        return checkPermutation(perm, points);
    }
};
