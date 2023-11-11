class Solution {
public:
    TreeNode* getLeaf(stack<TreeNode*>& stk) {
        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();
            auto cur = node->right;
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            if (!node->left && !node->right) {
                return node;
            }
        }
        return nullptr;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> stk1, stk2;

        auto node1 = root1;
        while (node1) {
            stk1.push(node1);
            node1 = node1->left;
        }

        auto node2 = root2;
        while (node2) {
            stk2.push(node2);
            node2 = node2->left;
        }

        TreeNode *l1, *l2;
        while (true) {
            l1 = getLeaf(stk1);
            l2 = getLeaf(stk2);
            if (!l1 && !l2) {
                return true;
            }
            if (!l1 || !l2 || l1->val != l2->val) {
                return false;
            }
        }

        return false;
    }
};
