class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> time(n, 0);
        stack<vector<int>> stk;
        for (const auto& log : logs) {
            const auto idx1 = log.find(':');
            const auto idx2 = log.find(':', idx1 + 1);

            const auto id = std::stoi(log.substr(0, idx1));
            const auto action = log.substr(idx1 + 1, idx2 - idx1 - 1);
            const auto timestamp = std::stoi(log.substr(idx2 + 1));

            if (action == "start") {
                if (!stk.empty()) {
                    time[stk.top()[0]] += timestamp - stk.top()[1];
                }
                stk.push({id, timestamp});
            } else {
                time[stk.top()[0]] += timestamp - stk.top()[1] + 1;
                stk.pop();
                if (!stk.empty()) {
                    stk.top()[1] = timestamp + 1;
                }
            }
        }
        return time;
    }
};