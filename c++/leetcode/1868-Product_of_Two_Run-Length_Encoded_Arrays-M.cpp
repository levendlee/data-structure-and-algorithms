class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        const int n1 = encoded1.size(), n2 = encoded2.size();
        vector<vector<int>> res;
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            int times = min(encoded1[i][1], encoded2[j][1]);
            int prod = encoded1[i][0] * encoded2[j][0];
            if (!res.empty() && res.back()[0] == prod) {
                res.back()[1] += times;
            } else {
                res.push_back({prod, times});
            }
            encoded1[i][1] -= times;
            if (!encoded1[i][1]) ++i;
            encoded2[j][1] -= times;
            if (!encoded2[j][1]) ++j;
        }
        return res;
    }
};
