class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int min_cost_0 = 0, min_cost_1 = 0;
        for (int c : cost) {
            int cur_min_cost = min(min_cost_0, min_cost_1) + c;
            min_cost_0 = min_cost_1;
            min_cost_1 = cur_min_cost;
        }
        return min(min_cost_0, min_cost_1);
    }
};
