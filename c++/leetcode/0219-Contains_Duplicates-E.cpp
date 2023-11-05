class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> num2idx;
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = num2idx.find(nums[i]);
            if (iter != num2idx.end() && (i - iter->second) <= k) {
                return true;
            }
            num2idx[nums[i]] = i;
        }
        return false;
    }
};
