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
