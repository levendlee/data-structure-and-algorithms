class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        if (arr.size() == 1) return arr[0];

        const int n = arr.size();
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && arr[i] == arr[j]) ++j;
            if (4 * (j - i) > n) return arr[i];
            i = j;
        }
        return 0;
    }
};