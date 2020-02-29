// 369 Plus One Linked List
// https://leetcode.com/problems/plus-one-linked-list

// version: 1; create time: 2020-01-18 21:18:50;
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
    ListNode* reverseLinkedList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            auto nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }

        return pre;
    }

    ListNode* plusOne(ListNode* head) {
        const auto reverse_head = reverseLinkedList(head);

        auto node = reverse_head;
        int carry = 1;
        while (node) {
            auto sum = node->val + carry;
            node->val = sum % 10;
            carry = sum / 10;
            if (!carry) {
                break;
            }
            if (!node->next) {
                node->next = new ListNode(carry);
                break;
            } else {
                node = node->next;
            }
        }

        return reverseLinkedList(reverse_head);
    }
};
