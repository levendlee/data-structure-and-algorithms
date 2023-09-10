// 332 Reconstruct Itinerary
// https://leetcode.com/problems/reconstruct-itinerary

// version: 1; create time: 2020-01-29 23:24:01;
class Solution {
private:
    bool dfs(unordered_map<string, vector<string>>& lut, vector<string>& res, const int n) {
        const auto& airport = res.back();
        if (res.size() == n + 1) {
            return true;
        }
        for (auto& next_airport : lut[airport]) {
            if (next_airport.empty()) continue;
            string tmp;
            res.push_back(next_airport);
            std::swap(tmp, next_airport);
            if (dfs(lut, res, n)) {
                return true;
            }
            res.pop_back();
            std::swap(tmp, next_airport);
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        const int n = tickets.size();
        unordered_map<string, vector<string>> lut;
        for (const auto& t : tickets) {
            lut[t[0]].push_back(t[1]);
        }
        for (auto& p : lut) {
            auto& v = p.second;
            std::sort(v.begin(), v.end());
        }
        vector<string> res = {"JFK"};
        dfs(lut, res, n);
        return res;
    }
};

// 2023/09/09

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> tickets_map;

        for (const auto& t : tickets) {
            tickets_map[t[0]].push_back(t[1]);
        }
        for (auto& [src, dst_vec] : tickets_map) {
            sort(dst_vec.begin(), dst_vec.end());
        }

        const int num_tickets = tickets.size();
        vector<string> itinerary;

        function<bool(const string&)> dfs;
        dfs = [&](const string& src) -> bool {
            itinerary.push_back(src);
            if (itinerary.size() == num_tickets + 1) {
                return true;
            }

            for (auto& dst : tickets_map[src]) {
                if (dst.empty()) {
                    continue;
                }
                string hold = dst;
                dst = "";
                if (dfs(hold)) {
                    return true;
                }
                dst = hold;
            }

            itinerary.pop_back();
            return false;
        };
        dfs("JFK");
        return itinerary;
    }
};
