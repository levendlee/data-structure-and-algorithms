// 274 H-Index
// https://leetcode.com/problems/h-index

// version: 1; create time: 2020-02-02 14:27:54;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int n = citations.size();
        vector<int> counter(n + 1, 0);
        for (const auto c : citations) {
            if (c >= n) {
                ++counter[n];
            } else {
                ++counter[c];
            }
        }

        int accu = 0;
        for (int i = n; i >= 0; --i) {
            accu += counter[i];
            if (accu >= i) return i;
        }
        return 0;
    }
};

// 2023/09/10
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        const int n = citations.size();
        for (int h = n; h > 0; --h) {
            int i = n - h;
            if (citations[i] >= h) {
                return h;
            }
        }
        return 0;
    }
};
