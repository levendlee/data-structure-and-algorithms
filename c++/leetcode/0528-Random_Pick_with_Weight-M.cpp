// 528 Random Pick with Weight
// https://leetcode.com/problems/random-pick-with-weight

// version: 1; create time: 2019-12-14 14:24:15;
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


// version: 2; create time: 2020-02-20 22:07:10;
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
