class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::unordered_map<string, int> hashmap;
        for (const auto& str : words) {
            ++hashmap[str];
        }
        priority_queue<pair<int, string>> pq;
        for (const auto& p : hashmap) {
            pq.emplace(-p.second, p.first);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<string> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};