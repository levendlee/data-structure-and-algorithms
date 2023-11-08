// 1004 Max Consecutive Ones III
// https://leetcode.com/problems/max-consecutive-ones-iii

// version: 1; create time: 2020-01-05 15:19:45;
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        const int n = A.size();
        int i = 0, j = 0;
        int len = 0;
        int count1 = 0;
        while (j < n) {
            count1 += A[j] == 1;
            while ((j - i + 1) - count1 > K) {
                count1 -= A[i++] == 1;
            }
            len = std::max(len, j - i + 1);
            ++j;
        }
        return len;
    }
};

//

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        const int n = nums.size();
        int longest = 0;
        int i = 0, j = 0, num_zeros = 0;
        while (j < n) {
            num_zeros += nums[j++] == 0;
            while (num_zeros > k) {
                num_zeros -= nums[i++] == 0;
            }
            longest = max(longest, j - i);
        }
        return longest;
    }
};
