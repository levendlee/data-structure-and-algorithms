class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i]) {
                indicies_.push_back(i);
                nums_.push_back(nums[i]);
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int n1 = indicies_.size(), n2 = vec.indicies_.size();
        int i = 0, j = 0;
        int dot = 0;
        while (i < n1 && j < n2) {
            if (indicies_[i] == vec.indicies_[j]) {
                dot += nums_[i++] * vec.nums_[j++];
            } else if (indicies_[i] < vec.indicies_[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return dot;
    }

private:
    vector<int> indicies_;
    vector<int> nums_;
};

