class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            stk_.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* node = stk_.top();
        stk_.pop();
        int val = node->val;
        
        if (node->right) {
            node = node->right;
            while (node) {
                stk_.push(node);
                node = node->left;
            }
        }
        return val;
    }
    
    bool hasNext() {
        return !stk_.empty();
    }

private:
    std::stack<TreeNode*> stk_;
};
