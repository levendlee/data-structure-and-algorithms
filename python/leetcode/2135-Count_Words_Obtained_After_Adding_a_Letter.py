class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        auto get_key = [](const std::string& s) {
            int key = 0;
            for (const auto& c : s) {
                key |= 1 << (c - 'a');
            }
            return key;
        };
        
        std::unordered_set<int> start_set;
        for (const auto& s : startWords) {
            start_set.insert(get_key(s));
        }

        int res = 0;
        for (const auto& s : targetWords) {
            int key = get_key(s);
            bool match = false;
            for (int i = 0; i < 26; ++i) {
                if (!(key & (1 << i))) continue;
                int search_key = key & ~(1 << i);
                match = start_set.find(search_key) != start_set.end();
                if (match) break;
            }
            res += match;
        }
        return res;
    }
};
