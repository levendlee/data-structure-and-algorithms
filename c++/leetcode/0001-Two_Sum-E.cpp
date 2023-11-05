class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num2idx;

        for (int i = 0; i < nums.size(); ++i) {
            auto iter = num2idx.find(target - nums[i]);
            if (iter != num2idx.end()) {
                return {i, iter->second};
            }
            num2idx[nums[i]] = i;
        }

        return {};
    }
};
