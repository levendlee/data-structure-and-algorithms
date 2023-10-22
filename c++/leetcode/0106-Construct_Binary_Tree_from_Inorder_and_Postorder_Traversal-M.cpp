class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) return nullptr;

        std::unordered_map<int, int> inorder_lookup;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_lookup[inorder[i]] = i; 
        }

        TreeNode* root;
        int postorder_idx = postorder.size() - 1;
        std::function<void(TreeNode*&, int, int)> buildPostorder;
        buildPostorder = [&](TreeNode*& node, int inorder_start, int inorder_end) {
            if (inorder_start > inorder_end || postorder_idx < 0) return;

            int val = postorder[postorder_idx--];
            node = new TreeNode(val);

            int inorder_idx = inorder_lookup[val];
            buildPostorder(node->right, inorder_idx + 1, inorder_end);
            buildPostorder(node->left, inorder_start, inorder_idx - 1);
        };
        buildPostorder(root, 0, inorder.size() - 1);

        return root;
    }
};
