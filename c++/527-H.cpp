class Solution {
public:
    void updateAbbrs(vector<string>& abbrs, int size, vector<int>& indices) {
        unordered_map<string, int> hashmap;
        for (int k = size - 2; k >= 2; --k) {
            for (const auto& i : indices) {
                if (i == -1) continue;
                auto abbr = abbrs[i].substr(0, size - k - 1) + to_string(k) + abbrs[i][size-1];
                ++hashmap[abbr];
            }
            for (auto& i : indices) {
                if (i == -1) continue;
                auto abbr = abbrs[i].substr(0, size - k - 1) + to_string(k) + abbrs[i][size-1];
                if (hashmap[abbr] == 1) {
                    abbrs[i] = abbr;
                    i = -1;
                }
            }
        }
    }

    vector<string> wordsAbbreviation(vector<string>& dict) {
        const int n = dict.size();
        vector<string> abbrs = dict;
        map<int, vector<int>> batches;
        for (int i = 0; i < n; ++i) {
            const int m = dict[i].size();
            batches[m].push_back(i);
        }
        for (auto p : batches) {
            updateAbbrs(abbrs, p.first, p.second);
        }
        return abbrs;
    }
};