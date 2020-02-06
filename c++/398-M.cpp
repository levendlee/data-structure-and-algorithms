class Solution {
private:
    vector<int> nums_;

public:
    Solution(vector<int>& nums) : nums_(nums) {

    }

    int pick(int target) {
        int res = -1;
        int cnt = 0;
        for (int i = 0; i < nums_.size(); ++i) {
            if (nums_[i] != target) continue;
            if (rand() % ++cnt == 0) {
                res = i;
            }
        }
        return res;
    }
};