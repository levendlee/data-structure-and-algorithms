class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num0 = INT_MAX;
        int num1 = INT_MAX;
        for (auto& n : nums) {
            if (n > num1) {
                return true;
            } else if (n > num0) {
                num1 = n;
            } else {
                num0 = n;
            }
        }
        return false;
    }
};