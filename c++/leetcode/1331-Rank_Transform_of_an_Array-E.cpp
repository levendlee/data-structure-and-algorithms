class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        const int n = arr.size();

        vector<int> idx(n, 0);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) { return arr[i] < arr[j]; });

        vector<int> res(n, 1);
        int rank = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[idx[i]] != arr[idx[i - 1]]) {
                ++rank;
            }
            res[idx[i]] = rank;
        }
        return res;
    }
};
