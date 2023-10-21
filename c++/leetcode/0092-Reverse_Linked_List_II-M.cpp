class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {        
        if (!head || !head->next || left == right) {
            return head;
        }

        ListNode* pre_head = new ListNode(0);
        pre_head->next = head;
        
        ListNode* l_start = head, *l_pre_start = pre_head;
        while (--left > 0) {
            l_pre_start = l_start;
            l_start = l_start->next;
        }

        ListNode* r_end = head, *r_post_end = head->next;
        while (--right > 0) {
            r_end = r_post_end;
            r_post_end = r_post_end->next;
        }

        // ... -> l_pre_start -> [l_start -> ... -> r_end] -> r_post_end

        l_pre_start->next = nullptr;
        r_end->next = nullptr;

        ListNode* cur = l_start->next, *pre = l_start;
        // pre -> cur -> nex
        // pre <- cur -> nex
        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        l_pre_start->next = r_end;
        l_start->next = r_post_end;

        return pre_head->next;
    }
};
