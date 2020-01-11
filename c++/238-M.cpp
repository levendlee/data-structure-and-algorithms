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