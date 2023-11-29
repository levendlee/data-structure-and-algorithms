// 636 Exclusive Time of Functions
// https://leetcode.com/problems/exclusive-time-of-functions

// version: 1; create time: 2020-01-30 21:28:55;
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

//

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        struct Log {
            int id;
            int timestamp;
            bool start;
        };

        auto parse = [](const string& s) {
            Log l;
            int sep0 = s.find(':');
            l.id = stoi(s.substr(0, sep0));
            int sep1 = s.find(':', sep0 + 1);
            l.start = s.substr(sep0 + 1, sep1 - sep0 -1) == "start";
            l.timestamp = stoi(s.substr(sep1 + 1));
            return l;
        };

        auto init_l = parse(logs[0]);
        int pre_timestamp;

        vector<int> time(n);
        stack<int> callstack;

        for (const auto& s : logs) {
            auto l = parse(s);
            if (l.start) {
                if (!callstack.empty()) {
                    time[callstack.top()] += l.timestamp - pre_timestamp;
                }
                pre_timestamp = l.timestamp;
                callstack.push(l.id);
            } else {
                time[l.id] += l.timestamp + 1 - pre_timestamp;
                pre_timestamp = l.timestamp + 1;
                callstack.pop();
            }
        }

        return time;
    }
};
