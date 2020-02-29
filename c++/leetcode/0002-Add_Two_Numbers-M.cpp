// 2 Add Two Numbers
// https://leetcode.com/problems/add-two-numbers

// version: 1; create time: 2019-12-31 10:48:46;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* const preHead = new ListNode(0);
        ListNode* node = preHead;
        int carry = 0;
        while (l1 || l2) {
            int lhs = l1 ? l1->val : 0; if (l1) l1 = l1->next;
            int rhs = l2 ? l2->val : 0; if (l2) l2 = l2->next;
            int sum = lhs + rhs + carry;
            node->next = new ListNode(sum % 10);
            node = node->next;
            carry = sum / 10;
        }
        if (carry) {
            node->next = new ListNode(carry);
        }
        return preHead->next;
    }
};
