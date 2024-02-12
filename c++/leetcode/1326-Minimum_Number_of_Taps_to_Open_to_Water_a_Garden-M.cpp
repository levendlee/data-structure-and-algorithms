class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        map<int, int> cover2taps;
        cover2taps[0] = 0;

        for (int i = 0; i < ranges.size(); ++i) {
            int lb = i - ranges[i];
            int rb = i + ranges[i];
            auto liter = cover2taps.lower_bound(lb);
            if (liter == cover2taps.end()) continue;
            int min_taps = liter->second + 1;
            auto riter = cover2taps.lower_bound(rb);
            if (riter != cover2taps.end() && riter->second <= min_taps) continue;
            vector<int> to_erase;
            while (liter != riter) {
                if (liter->second >= min_taps) {
                    to_erase.push_back(liter->first);
                }
                ++liter;
            }
            for (int index : to_erase) {
                cover2taps.erase(index);
            }
            cover2taps[rb] = min_taps;
        }

        auto iter = cover2taps.lower_bound(n);
        return iter == cover2taps.end() ? -1 : iter->second;
    }
};