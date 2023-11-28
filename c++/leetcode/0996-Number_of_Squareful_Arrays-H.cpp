// 996 Number of Squareful Arrays
// https://leetcode.com/problems/number-of-squareful-arrays

// version: 1; create time: 2020-02-16 13:28:25;
class Solution {
public:
    bool isSquareful(int num) {
        int root = sqrt(num);
        return (root * root) == num;
    }

    int backtracking(vector<int>& nums, vector<bool>& used, vector<int>& cur) {
        int cnt = 0;
        const int n = nums.size();
        if (cur.size() == n) return 1;
        int pre = -1;
        for (int i = 0; i < n; ++i) {
            if (used[i]) continue;
            if (!cur.empty() && !isSquareful(cur.back() + nums[i])) continue;
            if (nums[i] == pre) continue;
            used[i] = true;
            cur.push_back(nums[i]);
            pre = nums[i];
            cnt += backtracking(nums, used, cur);
            used[i] = false;
            cur.pop_back();
        }
        return cnt;
    }

    int numSquarefulPerms(vector<int>& A) {
        const int n = A.size();
        vector<bool> used(n, false);
        vector<int> cur;

        sort(A.begin(), A.end());
        return backtracking(A, used, cur);
    }
};

//

class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        auto is_sq = [&](int num) {
            int x = sqrt(num);
            return x * x == num;
        };

        const int n = nums.size();
        const int fullmask = (1 << n) - 1;

        function<int(int, int)> dfs;
        dfs = [&](int bitmask, int pre) {
            if (bitmask == fullmask) return 1;

            int total = 0;
            int pre_check = -1;
            for (int i = 0; i < n; ++i) {
                if (bitmask & (1 << i)) continue;
                if (nums[i] == pre_check) continue;
                pre_check = nums[i];
                if (bitmask == 0 || is_sq(pre + nums[i])) {
                    total += dfs(bitmask | (1 << i), nums[i]);
                }
            }
            return total;
        };

        return dfs(0, 0);
    }
};
