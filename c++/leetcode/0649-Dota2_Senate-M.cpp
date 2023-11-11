class Solution {
public:
    string predictPartyVictory(string senate) {
        const int n = senate.size();
        queue<int> rq, dq;
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') {
                rq.push(i);
            } else {
                dq.push(i);
            }
        }
        while (!rq.empty() && !dq.empty()) {
            int ri = rq.front(), di = dq.front();
            rq.pop(); dq.pop();
            if (ri < di) {
                rq.push(ri + n);
            } else {
                dq.push(di + n);
            }
        }
        return dq.empty() ? "Radiant" : "Dire";
    }
};
