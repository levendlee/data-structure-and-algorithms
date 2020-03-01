// 1354 Construct Target Array With Multiple Sums
// https://leetcode.com/problems/construct-target-array-with-multiple-sums

// version: 1; create time: 2020-02-29 22:29:12;
class Solution {
public:
    bool backTrack(vector<int>& cur) {
        const int n = cur.size();
        long sum = std::accumulate(cur.begin(), cur.end(), long(0));
        int cnt = std::count(cur.begin(), cur.end(), 1);
        if (cnt == n) return true;

        for (auto& num : cur) {
            if (sum - num < num) {
                auto tmp = num;
                num = num - (sum - num);
                if (backTrack(cur)) return true;
                num = tmp;
            }
        }
        return false;
    }

    bool isPossible(vector<int>& target) {
        return backTrack(target);
    }
};
