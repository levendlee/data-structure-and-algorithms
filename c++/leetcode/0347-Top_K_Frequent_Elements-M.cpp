// 347 Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements

// version: 1; create time: 2019-12-31 10:52:35;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for (const auto& n : nums) {
            ++counter[n];
        }
        priority_queue<pair<int, int>> pq;
        for (const auto& p : counter) {
            pq.emplace(-p.second, p.first);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second); pq.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

//

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnts;
        for (int n : nums) {
            ++cnts[n];
        }

        priority_queue<pair<int, int>> pq;
        for (const auto[n, cnt] : cnts) {
            pq.push({-cnt, n});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> res;
        while (!pq.empty()) {
            auto [ncnt, n] = pq.top();
            pq.pop();
            res.push_back(n);
        }
        return res;
    }
};
