class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        const int n = aliceValues.size();
        vector<int> realValues(n);
        for (int i = 0; i < n; ++i) {
            realValues[i] = aliceValues[i] + bobValues[i];
        }
        vector<int> index(n);
        std::iota(index.begin(), index.end(), 0);
        std::sort(index.begin(), index.end(), [&](const int i, const int j) { return realValues[i] > realValues[j]; });
        int alice_gain = 0, bob_gain = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                alice_gain += aliceValues[index[i]];
            } else {
                bob_gain += bobValues[index[i]];
            }
        }
        return alice_gain > bob_gain ? 1 : (alice_gain < bob_gain ? -1 : 0);
    }
};
