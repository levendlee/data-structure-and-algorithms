class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int buckets[101] = {0};
        for (const auto& h : heights) {
            ++buckets[h];
        }
        int cnt = 0;
        int cur = 0;
        for (const auto& h : heights) {
            while (buckets[cur] == 0) {
                ++cur;
            }
            if (h != cur) {
                ++cnt;
            }
            --buckets[cur];
        }
        return cnt;
    }
};