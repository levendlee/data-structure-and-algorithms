// 152 Maximum Product Subarray
// https://leetcode.com/problems/maximum-product-subarray

// version: 1; create time: 2020-02-01 15:45:36;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        long max_product = INT_MIN;
        long product = 1;
        int i = 0, j = 0;
        while (j <= n) {
            if (j == n || nums[j] == 0) {
                int s = i, e = j - 1;
                const auto cur_product = product;
                while (s < e) {
                    product /= nums[s++];
                    max_product = std::max(max_product, product);
                }
                s = i; e = j - 1; product = cur_product;
                while (s < e) {
                    product /= nums[e--];
                    max_product = std::max(max_product, product);
                }
                i = j + 1;
                product = 1;
                if (j != n) max_product = std::max(max_product, long(0));
            } else {
                product *= nums[j];
                max_product = std::max(max_product, product);
            }
            ++j;
        }
        return max_product;
    }
};
