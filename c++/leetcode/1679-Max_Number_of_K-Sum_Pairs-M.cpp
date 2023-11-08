class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> cnts;
        for (int n : nums) {
            ++cnts[n];
        }
        int ops = 0;
        for (auto& [n, cnt] : cnts) {
            if (k - n > n) {
                continue;
            } else if (k - n == n) {
                ops += cnt / 2;
            } else if (cnts.count(k - n)){
                ops += min(cnt, cnts[k - n]);
            }
        }
        return ops;
    }
};
