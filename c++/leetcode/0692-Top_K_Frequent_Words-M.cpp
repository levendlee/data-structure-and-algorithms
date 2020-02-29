// 692 Top K Frequent Words
// https://leetcode.com/problems/top-k-frequent-words

// version: 1; create time: 2019-12-30 11:34:15;
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
