class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int largest = 0;
        for (int i = 0; i < 32; ++i) {
            int count = 0;
            for (int number : candidates) {
                count += (number >> i) & 0x1;
            }
            largest = max(largest, count);
        }
        return largest;
    }
};