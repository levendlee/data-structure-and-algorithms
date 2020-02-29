// 852 Peak Index in a Mountain Array
// https://leetcode.com/problems/peak-index-in-a-mountain-array

// version: 1; create time: 2020-01-29 21:26:13;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        const int n = A.size();
        for (int i = 1; i < n - 1; ++i) {
            if (A[i-1] < A[i] && A[i] > A[i+1]) {
                return i;
            }
        }
        return 0;
    }
};
