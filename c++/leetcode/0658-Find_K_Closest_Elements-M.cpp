// 658 Find K Closest Elements
// https://leetcode.com/problems/find-k-closest-elements

// version: 1; create time: 2020-02-08 15:57:25;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int n = arr.size();

        int j = std::lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if (j == n || (j - 1 >= 0) && (abs(arr[j-1] - x) < abs(arr[j] - x))) {
            j = j - 1;
        }
        int i = j;

        while (j - i + 1 < k) {
            if (i - 1 < 0 || (j + 1 < n) && (abs(arr[j+1] - x) < abs(arr[i-1] - x))) {
                ++j;
            } else {
                --i;
            }
        }
        vector<int> res(arr.begin() + i, arr.begin() + j + 1);
        return res;
    }
};
