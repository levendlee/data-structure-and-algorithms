class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> buffer;

        function<void(TreeNode*)> inorder;
        inorder = [&](TreeNode* node) {
            if (!node) return;
            inorder(node->left);
            buffer.push_back(node);
            inorder(node->right);
        };
        inorder(root);

        // Cannot reuse inputs. Causes system crash.
        function<TreeNode*(int, int)> build_bst;
        build_bst = [&](int lo, int hi) -> TreeNode* {
            if (lo > hi) {
                return nullptr;
            }
            if (lo == hi) {
                return new TreeNode(buffer[lo]->val);
            }
            int mid = (lo + hi) / 2;
            TreeNode* node = new TreeNode(buffer[mid]->val);
            node->left = build_bst(lo, mid - 1);
            node->right = build_bst(mid + 1, hi);
            return node;
        };
        
        return build_bst(0, int(buffer.size()) - 1);
    }
};
