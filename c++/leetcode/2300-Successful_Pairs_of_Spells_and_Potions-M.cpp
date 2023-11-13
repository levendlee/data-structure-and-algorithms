class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // spells -> n; potions -> m;
        // Time O(mlogm + nlogm)
        // Space O(n)
        const int n = spells.size();
        sort(potions.begin(), potions.end());
        vector<int> results(n, 0);
        for (int i = 0; i < n; ++i) {
            long long min_p = success / spells[i];
            if (min_p * spells[i] < success) {
                ++min_p;
            }
            results[i] = potions.end() - lower_bound(potions.begin(), potions.end(), min_p);
        }
        return results;
    }
};
