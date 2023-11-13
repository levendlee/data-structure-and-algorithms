class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        long long max_hold = INT_MIN, max_nohold = 0;
        for (int p : prices) {
            max_nohold = max(max_nohold, max_hold + p - fee);
            max_hold = max(max_hold, max_nohold - p);
        }
        return max_nohold;
    }
};
