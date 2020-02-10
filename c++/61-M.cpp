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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;

        int size = 0;
        auto node = head;
        while (node) {
            node = node->next;
            ++size;
        }

        int offset = k % size;
        if (offset == 0) return head;

        // size = 4, offset = 1
        node = head;            // node -> 1
        for (int i = 0; i < size - offset - 1; ++i) {
            node = node->next;
        }
        auto cur_tail = node;   // cur_tail -> 3
        auto cur_head = node->next; // cur_head -> 4
        for (int i = 0; i < offset; ++i) {
            node = node->next;
        }                       // pre_tail -> 4
        auto pre_tail = node;
        pre_tail->next = head;
        cur_tail->next = nullptr;
        return cur_head;
    }
};