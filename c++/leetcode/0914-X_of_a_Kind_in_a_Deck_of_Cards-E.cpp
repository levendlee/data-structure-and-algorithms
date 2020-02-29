// 914 X of a Kind in a Deck of Cards
// https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards

// version: 1; create time: 2020-01-26 14:18:27;
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> counter;
        for (const auto& card : deck) {
            ++counter[card];
        }
        int min_cnt = INT_MAX;
        for (const auto& p: counter) {
            min_cnt = std::min(min_cnt, p.second);
        }
        const auto can_split = [&](const int i) {
            for (const auto& p : counter) {
                if (p.second % i) {
                    return false;
                }
            }
            return true;
        };

        for (int i = 2; i <= min_cnt; ++i) {
            if (can_split(i)) return true;
        }
        return false;
    }
};
