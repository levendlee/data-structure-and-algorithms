// 334 Increasing Triplet Subsequence
// https://leetcode.com/problems/increasing-triplet-subsequence

// version: 1; create time: 2019-10-30 23:40:00;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num0 = INT_MAX;
        int num1 = INT_MAX;
        for (auto& n : nums) {
            if (n > num1) {
                return true;
            } else if (n > num0) {
                num1 = n;
            } else {
                num0 = n;
            }
        }
        return false;
    }
};

//

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        const int n = nums.size();
        if (n < 3) return false;

        vector<int> smallest_vec(n + 1, 0);
        smallest_vec[0] = INT_MAX;
        for (int i = 0; i < n; ++i) {
            smallest_vec[i + 1] = min(smallest_vec[i], nums[i]);
        }

        int largest = INT_MIN;
        for (int i = n - 1; i >= 0; --i) {
            if (smallest_vec[i] < nums[i] && nums[i] < largest) return true;
            largest = max(largest, nums[i]);
        }

        return false;
    }
};

//

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num0 = INT_MAX;
        int num1 = INT_MAX;

        for (int n : nums) {
            if (n <= num0) {
                num0 = n;
            } else if (n <= num1) {
                num1 = n;
            } else {
                return true;
            }
        }

        return false;
    }
};
