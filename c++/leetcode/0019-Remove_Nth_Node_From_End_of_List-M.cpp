class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre_head = new ListNode(0, head);
        ListNode* pre = pre_head, *cur = head;
        int size = 0;
        while (cur) {
            cur = cur->next;
            ++size;
        }
        int idx = 0;
        cur = head;
        while (idx != (size - n)) {
            pre = cur;
            cur = cur->next;
            ++idx;
        }
        pre->next = cur->next;
        return pre_head->next;
    }
};
