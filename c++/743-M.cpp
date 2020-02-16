class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<bool> received(N + 1, false);

        unordered_map<int, vector<vector<int>>> edges;
        for (const auto& t : times) {
            edges[t[0]].push_back({t[1], t[2]});
        }

        int delay = 0;
        priority_queue<vector<int>> pq;
        pq.push({0, K});

        while (!pq.empty()) {
            auto d = -pq.top()[0];
            auto node = pq.top()[1];
            pq.pop();

            if (received[node]) continue;
            received[node] = true;

            delay = max(delay, d);
            for (const auto& e : edges[node]) {
                auto v = e[0], w = e[1];
                pq.push({-w-d, v});
            }
        }

        auto cnt = accumulate(received.begin(), received.end(), 0);
        if (cnt != N) return -1;
        return delay;
    }
};