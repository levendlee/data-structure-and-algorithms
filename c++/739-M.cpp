class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        const int n = T.size();
        stack<int> stk;
        vector<int> wait(n, 0);
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && T[stk.top()] < T[i]) {
                wait[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return wait;
    }
};