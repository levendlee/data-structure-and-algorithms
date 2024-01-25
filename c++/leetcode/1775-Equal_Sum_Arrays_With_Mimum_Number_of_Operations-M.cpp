class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (sum1 < sum2) {
            swap(sum1, sum2);
            swap(nums1, nums2);
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = nums1.size(), n2 = nums2.size();
        int i = n1 - 1, j = 0, ops = 0;
        while ((i >= 0 || j < n2) && sum1 > sum2) {
            int diff1 = i < 0 ? 0 : nums1[i] - 1;
            int diff2 = j >= n2 ? 0 : 6 - nums2[j];
            if (i < 0 || diff1 < diff2) {
                sum2 += diff2;
                ++j;
            } else {
                sum1 -= diff1;
                --i;
            }
            ++ops;
        }
        return sum1 > sum2 ? -1 : ops;
    }
};