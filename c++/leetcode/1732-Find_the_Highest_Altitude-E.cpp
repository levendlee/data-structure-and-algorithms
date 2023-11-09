class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int largest = 0;
        int sum = 0;
        for (int g : gain) {
            largest = max(largest, sum += g);
        }
        return largest;
    }
};
