/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* inorder(Node* root, Node* pred) {
        if (!root) return nullptr;

        if (root->left) {
            pred = inorder(root->left, pred);
        }
        pred->right = root;
        root->left = pred;
        auto succ = root;
        if (root->right) {
            succ = inorder(root->right, root);
        }
        return succ;
    }

    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        auto pre_head = new Node();
        auto succ = inorder(root, pre_head);
        auto pred = pre_head->right;
        succ->right = pred;
        pred->left = succ;
        return pred;
    }
};