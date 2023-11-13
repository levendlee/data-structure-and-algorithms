class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int n = temperatures.size();

        vector<int> days(n, 0);
        stack<int> idx_stk;
        for (int i = 0; i < n; ++i) {
            int t = temperatures[i];
            while (!idx_stk.empty() && temperatures[idx_stk.top()] < t) {
                int idx = idx_stk.top();
                idx_stk.pop();
                days[idx] = i - idx;
            }
            idx_stk.push(i);
        }

        return days;
    }
};
