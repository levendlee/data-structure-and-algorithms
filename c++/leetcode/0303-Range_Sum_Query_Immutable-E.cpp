class NumArray {
public:
    NumArray(vector<int>& nums) : cumsum_(nums.size()){
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            cumsum_[i] = sum;
        }
    }
    
    int sumRange(int left, int right) {
        return cumsum_[right] - (left == 0 ? 0 : cumsum_[left - 1]);
    }
    
private:
    vector<int> cumsum_;
};