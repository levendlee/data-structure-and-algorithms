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