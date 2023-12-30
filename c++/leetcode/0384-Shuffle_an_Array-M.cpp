class Solution {
public:
    Solution(vector<int>& nums) {
        nums_ = nums;
    }
    
    vector<int> reset() {
        return nums_;   
    }
    
    vector<int> shuffle() {
        int n = nums_.size();
        vector<int> shuffled = nums_;
        for (int i = 0; i < n; ++i) {
            int j = i + rand() % (n - i);
            std::swap(shuffled[i], shuffled[j]);
        }
        return shuffled;
    }

private:
    vector<int> nums_;
};

