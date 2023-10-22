class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;

        TreeNode* root;
        int preorder_idx = 0;
        std::function<void(TreeNode**, int, int)> buildPreorder;
        buildPreorder = [&](TreeNode** node, int inorder_start, int inorder_end) {
            if (inorder_start > inorder_end) return;

            int val = preorder[preorder_idx++];
            *node = new TreeNode(val);
            
            int inorder_idx = std::find(inorder.begin() + inorder_start, inorder.begin() + inorder_end + 1, val) - inorder.begin();
            buildPreorder(&(*node)->left, inorder_start, inorder_idx - 1);
            buildPreorder(&(*node)->right, inorder_idx + 1, inorder_end);
        };
        buildPreorder(&root, 0, inorder.size() - 1);

        return root;
    }
};
