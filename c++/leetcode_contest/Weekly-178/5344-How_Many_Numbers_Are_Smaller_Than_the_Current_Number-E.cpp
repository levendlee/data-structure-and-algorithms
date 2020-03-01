// 5344. How Many Numbers Are Smaller Than the Current Number
// https://leetcode.com/contest/weekly-contest-178/problems/how-many-numbers-are-smaller-than-the-current-number/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int cnt[101] = {0};
        for (auto& n : nums) cnt[n]++;
        for (int i = 1; i < 101; ++i) {
            cnt[i] += cnt[i-1];
        }
        vector<int> res(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                res[i] = cnt[nums[i]-1];
            }
        }
        return res;
    }
};