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

//

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        auto run_one_op = [](double a, double b) {
            vector<double> res = {a + b, a - b, b - a, a * b};
            if (a != 0) res.push_back(b / a);
            if (b != 0) res.push_back(a / b);
            return res;
        };

        function<bool(const vector<double>& nums)> search;
        search = [&](const vector<double>& nums) {
            if (nums.size() == 3) {
                for (auto n : nums) {
                    cout << n << ", ";
                }
                cout << "\n";
            }
            
            if (nums.size() == 1) {
                return abs(nums[0] - 24.0) < 1e-1;
            }
            int n = nums.size();
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    auto new_nums = run_one_op(nums[i], nums[j]);
                    vector<double> next_nums;
                    for (int k = 0; k < n; ++k) {
                        if (i == k || j == k) continue;
                        next_nums.push_back(nums[k]);
                    }
                    for (double ret : new_nums) {
                        next_nums.push_back(ret);
                        if (search(next_nums)) {
                            return true;
                        }
                        next_nums.pop_back();
                    }
                }
            }
            return false;
        };

        vector<double> dcards;
        for (int num : cards) {
            dcards.push_back(static_cast<double>(num));
        }
        return search(dcards);
    }
};