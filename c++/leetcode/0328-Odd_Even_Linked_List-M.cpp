// 328 Odd Even Linked List
// https://leetcode.com/problems/odd-even-linked-list

// version: 1; create time: 2020-01-29 21:26:13;
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd_head = new ListNode(0);
        ListNode* even_head = new ListNode(0);

        int i = 0;
        auto node = head;
        auto odd = odd_head;
        auto even = even_head;
        while (node) {
            if (++i % 2) {
                odd->next = node;
                odd = node;
            } else {
                even->next = node;
                even = node;
            }
            node = node->next;
        }
        odd->next = even_head->next;
        even->next = nullptr;
        return odd_head->next;
    }
};

//

lass Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd_pre_head = new ListNode();
        auto odd = odd_pre_head;
        ListNode* even_pre_head = new ListNode();
        auto even = even_pre_head;

        int i = 1;
        ListNode* node = head;
        while (node) {
            if (i++ & 0x1) {
                odd = odd->next = node;
            } else {
                even = even->next = node;
            }
            node = node->next;
        }

        odd->next = even_pre_head->next;
        even->next = nullptr;

        return odd_pre_head->next;
    }
};
