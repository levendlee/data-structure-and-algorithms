class Solution {
private:
    vector<int> sums;

public:
    Solution(vector<int>& w) : sums(w) {
        const int n = sums.size();
        for (int i = 1; i < n; ++i) {
            sums[i] += sums[i-1];
        }
    }

    int pickIndex() {
        int pick = (rand() % (sums.back())) + 1;
        return lower_bound(sums.begin(), sums.end(), pick) - sums.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */