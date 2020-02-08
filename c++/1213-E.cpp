class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int n1 = arr1.size(), n2 = arr2.size(), n3 = arr3.size();
        int i = 0, j = 0, k = 0;
        vector<int> res;
        while (i < n1 && j < n2 && k < n3) {
            int min_v = std::min(std::min(arr1[i], arr2[j]), arr3[k]);
            if (min_v == arr1[i] && min_v == arr2[j] && min_v == arr3[k]) {
                res.push_back(arr1[i]);
                ++i; ++j; ++k;
            } else if (min_v == arr1[i]) {
                ++i;
            } else if (min_v == arr2[j]) {
                ++j;
            } else {
                ++k;
            }
        }
        return res;
    }
};