#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int ShortestTwoNonOverlappingSubarrays(const vector<int>& arr, int target) {
    const int n = arr.size();

    unordered_map<int, int> sums;
    sums[0] = -1;
    vector<int> dp(n + 1, INT_MAX);
    int shortest = INT_MAX;

    int cur_sum = 0;
    for (int i = 0; i < n; ++i) {
        cur_sum += arr[i];
        if (sums.count(cur_sum - target)) {
            int idx = sums[cur_sum - target];
            int size = i - idx;
            if (dp[idx+1] != INT_MAX) {
                shortest = min(shortest, dp[idx+1] + size);
            }
            dp[i+1] = min(dp[i], size);
        } else {
            dp[i+1] = dp[i];
        }
        sums[cur_sum] = i;
        //cout << dp[i+1] << "\n";
    }

    return shortest;
}

int main() {
    vector<int> arr1 = {1,2,2,1,1,1};
    cout << ShortestTwoNonOverlappingSubarrays(arr1, 3) << "\n";

    vector<int> arr2 = {2,2,1,4,1,3};
    cout << ShortestTwoNonOverlappingSubarrays(arr2, 5) << "\n";
    return 0;
}