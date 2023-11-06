class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        const int n = nums.size();
        function<TreeNode*(int, int)> build_tree;
        build_tree = [&](int lo, int hi) -> TreeNode* {
            if (lo > hi) return nullptr;
            int mid = (lo + hi + 1) / 2;
            return new TreeNode(nums[mid], build_tree(lo, mid - 1), build_tree(mid + 1, hi));
        };
        return build_tree(0, n - 1);
    }
};
