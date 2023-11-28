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

//

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int n = arr.size();

        int j = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if (j == n) j = n - 1;
        int i = j - 1;
        if (i < 0) i = 0;

        auto is_closer = [&](int a, int b) {
            return (abs(a - x) < abs(b - x)) || (abs(a - x) == abs(b - x) && a < b);
        };

        // Start with range size 1.
        if (is_closer(arr[i], arr[j])) {
            // Should include i.
            j = i;
        } else {
            // Should include j.
            i = j;
        }

        while (j - i + 1 < k) {
            if (j == n - 1 || i != 0 && is_closer(arr[i - 1], arr[j + 1])) {
                --i;
            } else {
                ++j;
            }
        }

        return vector<int>(arr.begin() + i, arr.begin() + j + 1);
    }
};
