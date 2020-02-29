// 75 Sort Colors
// https://leetcode.com/problems/sort-colors

// version: 1; create time: 2020-02-01 22:06:57;
class Solution {
public:
    void sortColors(vector<int>& A) {
        const int n = A.size();
        int idx0 = 0, idx1 = 0, idx2 = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 0) {
                A[idx2++] = 2;
                A[idx1++] = 1;
                A[idx0++] = 0;
            } else if (A[i] == 1) {
                A[idx2++] = 2;
                A[idx1++] = 1;
            } else {
                A[idx2++] = 2;
            }
        }
    }
};


// version: 2; create time: 2020-02-20 21:42:06;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int n = nums.size();
        int i = 0, j = 0, k = 0;
        for (int t = 0; t < n; ++t) {
            if (nums[t] == 0) {
                nums[k++] = 2;
                nums[j++] = 1;
                nums[i++] = 0;
            } else if (nums[t] == 1) {
                nums[k++] = 2;
                nums[j++] = 1;
            } else {
                nums[k++] = 2;
            }
        }
    }
};
