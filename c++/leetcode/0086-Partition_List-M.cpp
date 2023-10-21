class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small_prehead = new ListNode(0);
        ListNode* large_prehead = new ListNode(0);
        ListNode* small_tail = small_prehead;
        ListNode* large_tail = large_prehead;

        ListNode* cur = head;
        while (cur) {
            std::cout << cur->val << "\n";
            if (cur->val < x) {
                small_tail->next = cur;
                small_tail = cur;
            } else {
                large_tail->next = cur;
                large_tail = cur;
            }
            cur = cur->next;
        }

        small_tail->next = large_prehead->next;
        large_tail->next = nullptr;
        return small_prehead->next;
    }
};
