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