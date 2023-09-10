// 238 Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self

// version: 1; create time: 2020-01-11 17:00:26;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for (int i = 1; i < n; ++i) {
            left[i] = nums[i-1] * left[i-1];
        }
        for (int i = n - 2; i >= 0; --i) {
            right[i] = nums[i+1] * right[i+1];
        }
        vector<int> res(n, 1);
        for (int i = 0; i < n; ++i) {
            res[i] = left[i] * right[i];
        }
        return res;
    }
};

// 2023/09/10

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> l_accu(n, 1);
        for (int i = 0; i < n - 1; ++i) {
            l_accu[i + 1] = l_accu[i] * nums[i];
        }
        int r_accu = 1;
        vector<int> res(n, 1);
        for (int i = n - 1; i >= 0; --i) {
            res[i] = l_accu[i] * r_accu;
            r_accu *= nums[i];
        }
        return res;
    }
};
