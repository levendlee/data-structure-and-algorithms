public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* pre_head = new ListNode();
        pre_head->next = head;

        // 1. Find middle node as `slow`
        ListNode *fast = head, *slow = head, *pre_slow = pre_head;
        while (fast && fast->next) {
            fast = fast->next->next;
            pre_slow = slow;
            slow = slow->next;
        }

        // 2. Remove middle node
        pre_slow->next = slow->next;
        delete slow;
        return pre_head->next;
    }
};
