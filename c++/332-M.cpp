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