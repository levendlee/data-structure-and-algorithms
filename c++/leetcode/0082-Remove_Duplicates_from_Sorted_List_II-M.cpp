class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* pre_head = new ListNode(0, head);
        ListNode *pre = pre_head, *cur=head;
        while (cur) {
            int val = cur->val;
            if (cur->next && cur->next->val == val) {
                while (cur && cur->val == val) {
                    ListNode* tmp = cur;
                    cur = cur->next;
                    delete tmp;
                }
                pre->next = cur;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return pre_head->next;
    }
};
