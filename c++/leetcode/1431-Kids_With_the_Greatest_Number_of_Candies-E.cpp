class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        const int n = candies.size();

        vector<bool> res(n, false);
        int max_candies = *max_element(candies.begin(), candies.end());
        for (int i = 0; i < n; ++i) {
            res[i] = candies[i] + extraCandies >= max_candies;
        }
        return res;
    }
};
