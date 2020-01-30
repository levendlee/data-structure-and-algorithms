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