class Solution {
private:
    vector<int> tmp_;
    vector<int> count_;

    void mergeSort(const vector<int>& nums, vector<int>& idx, const int start, const int end) {
        if (end - start <= 0) return;

        const int mid = (start + end) / 2;
        mergeSort(nums, idx, start, mid);
        mergeSort(nums, idx, mid + 1, end);

        int i = start, j = mid + 1, k = start;
        while (i <= mid || j <= end) {
            if ((j > end) || (i <= mid) && (nums[idx[i]] > nums[idx[j]])) {
                count_[idx[i]] += end - j + 1;
                tmp_[k++] = idx[i++];
            } else {
                tmp_[k++] = idx[j++];
            }
        }
        std::copy(tmp_.begin() + start, tmp_.begin() + end + 1, idx.begin() + start);
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        const int n = nums.size();

        count_ = vector<int>(n, 0);
        auto idx = vector<int>(n, 0);
        std::iota(idx.begin(), idx.end(), 0);
        tmp_ = idx;

        mergeSort(nums, idx, 0, n - 1);
        return count_;
    }
};