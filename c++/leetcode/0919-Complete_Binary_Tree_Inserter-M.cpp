/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        root_ = root;
        if (!root) return;
        dq_.push_back(root);
        while (true) {
            TreeNode* node = dq_.front();
            if (!node->left) break;
            dq_.push_back(node->left);
            if (!node->right) break;
            dq_.push_back(node->right);
            dq_.pop_front();
        }
    }
    
    int insert(int val) {
        TreeNode* new_node = new TreeNode(val);
        if (dq_.empty()) {
            root_ = new_node;
            dq_.push_back(root_);
            return val;
        }
        TreeNode* node = dq_.front();
        if (!node->left) {
            node->left = new_node;
        } else {
            node->right = new_node;
            dq_.pop_front();
        }
        dq_.push_back(new_node);
        return node->val;
    }
    
    TreeNode* get_root() {
        return root_;
    }

private:
    TreeNode* root_;
    deque<TreeNode*> dq_;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */