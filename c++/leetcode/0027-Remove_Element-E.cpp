class Solution {
public:
    int removeElement(vector<int>& nums, int val) {        
        const int n = nums.size();
        int i = 0, j = 0;
        while (j < n) {
            while (j < n && nums[j] == val) ++j;
            if (j < n) nums[i++] = nums[j++];
        }
        return i;
    }
};
