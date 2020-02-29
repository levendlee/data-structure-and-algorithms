// 969 Pancake Sorting
// https://leetcode.com/problems/pancake-sorting

// version: 1; create time: 2020-02-07 23:16:27;
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        const int n = A.size();
        int i = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (A[i] != i + 1) {
                int idx = std::find(A.begin(), A.end(), i + 1) - A.begin();
                res.push_back(idx + 1);
                std::reverse(A.begin(), A.begin() + idx + 1);
                res.push_back(i + 1);
                std::reverse(A.begin(), A.begin() + i + 1);
            }
        }
        return res;
    }
};
