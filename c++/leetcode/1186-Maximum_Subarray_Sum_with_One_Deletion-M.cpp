class Solution {
public:
    int maximumSum(vector<int>& arr) {
        const int n = arr.size();
        if (n == 1) return arr[0];
        int max_sum = INT_MIN;

        vector<int> lsum(n, 0), rsum(n, 0);
        lsum[0] = 0;
        for (int i = 1; i < n; ++i) {
            lsum[i] = lsum[i - 1] > 0 ? lsum[i - 1] + arr[i - 1] : arr[i - 1];
            max_sum = max(max_sum, lsum[i]);
        }
        rsum[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i) {
            rsum[i] = rsum[i + 1] > 0 ? rsum[i + 1] + arr[i + 1] : arr[i + 1];
            max_sum = max(max_sum, rsum[i]);
        }

        
        max_sum = max(max_sum, rsum[0]);
        max_sum = max(max_sum, lsum[n - 1]);
        for (int i = 1; i < n - 1; ++i) {
            int l = lsum[i];
            int r = rsum[i];
            max_sum = max({max_sum, lsum[i] + rsum[i], lsum[i + 1] + rsum[i]});
        }

        return max_sum;
    }
};
