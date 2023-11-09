class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> num2cnt;
        for (int n : arr) {
            ++num2cnt[n];
        }
        unordered_set<int> cnt_set;
        for (auto [num, cnt] : num2cnt) {
            if (cnt_set.count(cnt)) return false;
            cnt_set.insert(cnt);
        }
        return true;
    }
};
