// 5346. Linked List in Binary Tree
// https://leetcode.com/contest/weekly-contest-178/problems/linked-list-in-binary-tree/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool preOrder(ListNode* head, const vector<ListNode*>& nodes, TreeNode* root) {
        if (!root) {
            for (auto& node : nodes) {
                if (!node) return true;
            }
            return false;
        }
        vector<ListNode*> cur_nodes;
        if (head->val == root->val) {
            if (!head->next) return true;
            cur_nodes.push_back(head->next);
        }
        for (auto& node : nodes) {
            if (node->val == root->val) {
                if (!node->next) return true;
                cur_nodes.push_back(node->next);
            }
        }
        if (preOrder(head, cur_nodes, root->left) || preOrder(head, cur_nodes, root->right)) return true;
        return false;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<ListNode*> nodes;
        return preOrder(head, nodes, root);
    }
};