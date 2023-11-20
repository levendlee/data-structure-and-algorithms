// 426 Convert Binary Search Tree to Sorted Doubly Linked List
// https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list

// version: 1; create time: 2020-01-16 00:18:43;
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

//

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) {
            return nullptr;
        }

        function<pair<Node*, Node*>(Node*)> inorder;
        inorder = [&](Node* root) -> pair<Node*, Node*> {
            if (!root) {
                return {nullptr, nullptr};
            }
            auto [lmin, lmax] = inorder(root->left);
            if (lmax) {
                lmax->right = root;
                root->left = lmax;
            }
            auto [rmin, rmax] = inorder(root->right);
            if (rmin) {
                root->right = rmin;
                rmin->left = root;
            }
            return {lmin ? lmin : root, rmax ? rmax : root};
        };
        auto [tree_min, tree_max] = inorder(root);
        tree_min->left = tree_max;
        tree_max->right = tree_min;
        return tree_min;
    }
};

//

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) {
            return nullptr;
        }

        function<Node*(Node*, Node*)> inorder;
        inorder = [&](Node* cur, Node* pre) {
            if (!cur) return pre;
            pre = inorder(cur->left, pre);
            pre->right = cur;
            cur->left = pre;
            return inorder(cur->right, cur);
        };

        Node* prehead = new Node(0);
        auto tail = inorder(root, prehead);
        auto head = prehead->right;
        head->left = tail;
        tail->right = head;

        return head;
    }
};
