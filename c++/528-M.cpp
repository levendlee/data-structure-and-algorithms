class Solution {
private:
    vector<int> sums_;
    int total_sum_;

public:
    Solution(vector<int>& w) : sums_(w.size() + 1), total_sum_(0) {
        const int n = w.size();
        sums_[0] = 0;
        for (int i = 0; i < n; ++i) {
            sums_[i + 1] = sums_[i] + w[i];
            total_sum_ += w[i];
        }
    }

    int pickIndex() {
        // For example, weights are [1, 2, 97], sums are [1, 3, 100]
        // Then there is 1% of pick is [1, 1]
        //               2% of pick is [2, 3]
        //               3% of pick is [4, 100]
        int pick = rand() % total_sum_ + 1;
        return std::lower_bound(sums_.begin() + 1, sums_.end(), pick) - sums_.begin() - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */