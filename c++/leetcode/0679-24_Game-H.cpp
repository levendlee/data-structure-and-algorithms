// 679 24 Game
// https://leetcode.com/problems/24-game

// version: 1; create time: 2019-10-22 23:48:54;
// This is ugly as hell. Need to redo this.
class Solution {
public:
    void addHelper2(std::unordered_set<float>& c_set, float a, float b) {
        c_set.insert(a + b);
        c_set.insert(a - b);
        c_set.insert(a * b);
        if (b != 0)
            c_set.insert(1.0 * a / b);
    }

    void addHelper1(std::unordered_set<float>& c_set, float a, float b) {
        addHelper2(c_set, a, b);
        addHelper2(c_set, b, a);
    }

    bool find24(std::unordered_set<float>& c_set) {
        for (auto& num: c_set) {
            if (fabs(num - 24.0) < 1e-3) {
                return true;
            }
        }
        return false;
    }

    bool doCalculations(vector<int>& cur) {
        unordered_set<float> nums1, nums2, nums3;
        addHelper1(nums1, cur[0], cur[1]);
        for (auto& l : nums1) {
            addHelper1(nums2, l, cur[2]);
        }
        for (auto& l : nums2) {
            addHelper1(nums3, l, cur[3]);
        }
        if (find24(nums3)) return true;

        nums2.clear();
        nums3.clear();
        addHelper1(nums2, cur[2], cur[3]);
        for (auto& l : nums1) {
            for (auto& r : nums2) {
                addHelper1(nums3, l, r);
            }
        }
        return find24(nums3);
    }

    bool getPermutations(vector<int>& nums, vector<int>& cur, vector<bool>& visit) {
        if (cur.size() == nums.size()) {
            if (doCalculations(cur)) return true;
        }

        for (int i = 0; i < 4; ++i) {
            if (!visit[i]) {
                visit[i] = true;
                cur.push_back(nums[i]);
                if (getPermutations(nums, cur, visit)) return true;
                cur.pop_back();
                visit[i] = false;
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& nums) {
        vector<int> cur;
        vector<bool> visit(4, false);
        return getPermutations(nums, cur, visit);
    }
};
