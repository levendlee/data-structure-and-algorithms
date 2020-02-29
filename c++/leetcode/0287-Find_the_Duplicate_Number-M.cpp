// 287 Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number

// version: 1; create time: 2020-02-02 16:25:13;
class Solution {
public:
    int findDuplicate(const vector<int>& nums) {
        int fast = nums[0];
        int slow = nums[0];
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast != slow);

        slow = nums[0];
        while (slow != fast) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};
