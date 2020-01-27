class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        const int n = arr.size();
        /*
        vector<int> marker(n, 0);
        int chunks = 0;
        int in_range = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] <= i) ++in_range;
            in_range += marker[i];
            if (in_range == i + 1) ++chunks;
            marker[arr[i]] = 1;
        }
        */
        int chunks = 0;
        for (int i = 0; i < n; ++i) {
            arr[i] = std::max(arr[i], i > 0 ? arr[i-1] : arr[i]);
            if (arr[i] == i) ++chunks;
        }
        return chunks;
    }
};