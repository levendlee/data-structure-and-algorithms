// 122 Best Time to Buy and Sell Stock II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

// version: 1; create time: 2020-01-08 23:26:43;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = 0;
        const int n = prices.size();
        int i = 0;
        while (i + 1 < n && prices[i] >= prices[i + 1]) ++i;
        while (i < n) {
            buy = prices[i];
            while (i + 1 < n && prices[i] <= prices[i+1]) ++i;
            profit += prices[i] - buy;
            ++i;
        }
        return profit;
    }
};

// 2023/09/10
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_hold = INT_MIN;
        int max_nohold = 0;
        for (int p : prices) {
            int nex_max_hold = std::max(max_nohold - p, max_hold);
            int nex_max_nohold = std::max(max_hold + p, max_nohold);
            max_hold = nex_max_hold;
            max_nohold = nex_max_nohold;
        }
        return max_nohold;
    }
};
