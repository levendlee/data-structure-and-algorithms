// 410 Split Array Largest Sum
// https://leetcode.com/problems/split-array-largest-sum

// version: 1; create time: 2020-02-18 20:35:26;
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long lo = *max_element(nums.begin(), nums.end());
        long hi = accumulate(nums.begin(), nums.end(), 0L);
        long res = INT_MAX;
        while (lo <= hi) {
            auto mid = lo + (hi - lo + 1) / 2;
            long cnt = 1, sum = 0, max_sum = 0;
            for (const auto& n : nums) {
                sum += n;
                if (sum > mid) {
                    ++cnt;
                    max_sum = max(max_sum, sum - n);
                    sum = n;
                }
            }
            max_sum = max(max_sum, sum);
            if (cnt <= m) {
                res = min(max_sum, res);
            }
            if (cnt <= m) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return res;
    }
};

//

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int sum = 0, splits = 0;
            for (int n : nums) {
                if (sum + n > mid) {
                    ++splits;
                    sum = n;
                } else {
                    sum += n;
                }
            }
            splits += sum > 0;
            if (splits > k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        return lo;
    }
};

//

class Solution
{
public:
    int splitArray(vector<int> &nums, int k)
    {
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);

        const int n = nums.size();
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            int sum = 0, split = 0;
            for (int i = 0; i < n; ++i)
            {
                if (sum + nums[i] > mid)
                {
                    ++split;
                    sum = nums[i];
                }
                else
                {
                    sum += nums[i];
                }
            }
            if (sum)
            {
                ++split;
            }

            if (split > k)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }

        return lo;
    }
};