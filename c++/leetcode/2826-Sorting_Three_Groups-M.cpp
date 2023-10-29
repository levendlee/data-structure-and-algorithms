class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ends1(n + 1, 0);
        vector<int> ends2(n + 1, 0);
        vector<int> ends3(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int num = nums[i - 1];
            ends1[i] = ends1[i - 1] + (num != 1);
            ends2[i] = std::min(ends1[i - 1], ends2[i - 1]) + (num != 2);
            ends3[i] = std::min(std::min(ends1[i - 1], ends2[i - 1]), ends3[i - 1]) + (num != 3);
            //std::cout << ends1[i] << ", " << ends2[i] << ", " << ends3[i] << "\n"; 
        }
        return std::min(std::min(ends1.back(), ends2.back()), ends3.back());
    }
};

