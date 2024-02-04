class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        function<int(TreeNode* root)> dfs;
        dfs = [&](TreeNode* node) {
            if (!node) return 0;
            if (node->val > high) {
                return dfs(node->left);
            } else if (node->val < low) {
                return dfs(node->right);
            } else {
                return dfs(node->left) + dfs(node->right) + node->val;
            }
        };
        return dfs(root);
    }
};

//

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> travel_costs(n + 1, INT_MAX);
        travel_costs[0] = 0;

        for (int i = 0; i < n; ++i) {
            int cost_1day = travel_costs[i] + costs[0];
            int prev_7days = lower_bound(days.begin(), days.end(), days[i] - 6) - days.begin();
            int cost_7days = travel_costs[prev_7days] + costs[1];
            int prev_30days = lower_bound(days.begin(), days.end(), days[i] - 29) - days.begin();
            int cost_30days = travel_costs[prev_30days] + costs[2];
            travel_costs[i + 1] = min({cost_1day, cost_7days, cost_30days});
        }

        return travel_costs.back();
    }
};