// 398 Random Pick Index
// https://leetcode.com/problems/random-pick-index

// version: 1; create time: 2020-02-06 00:03:47;
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

//

class Solution {
public:
    Solution(vector<int>& nums) {
        const int n = nums.size();
        num2idx_.resize(n);
        for (int i = 0; i < n; ++i) {
            num2idx_[i] = {nums[i], i};
        }
        sort(num2idx_.begin(), num2idx_.end());
    }

    int pick(int target) {
        const int n = num2idx_.size();
        auto iter0 = lower_bound(num2idx_.begin(), num2idx_.end(), make_pair(target, 0));
        auto iter1 = lower_bound(num2idx_.begin(), num2idx_.end(), make_pair(target, n));
        int choices = iter1 - iter0;
        int pick = (iter0 + (rand() % choices))->second;
        return pick;
    }

private:
    vector<pair<int, int>> num2idx_;
};
