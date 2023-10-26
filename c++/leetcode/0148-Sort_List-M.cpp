class Solution {
public:
    ListNode* sortList(ListNode* head) {
        function<ListNode*(ListNode*, ListNode*)> merge_sorted_list;
        ListNode* prehead = new ListNode();
        merge_sorted_list = [&](ListNode* l, ListNode* r) {
            ListNode* node = prehead;
            while (l || r) {
                if (!l || r && (r->val < l->val)) {
                    node->next = r;
                    node = r;
                    r = r->next;
                } else {
                    node->next = l;
                    node = l;
                    l = l->next;
                }
            }
            node = prehead->next;
            while (node) {
                node = node->next;
            }
            return prehead->next;
        };

        function<ListNode*(ListNode*)> sort_list;
        sort_list = [&](ListNode* l1) {
            if (!l1 || !l1->next) return l1;

            ListNode *fast = l1->next, *slow = l1;
            while (fast && fast->next) {
                fast = fast->next->next;
                slow = slow->next;
            }
            
            ListNode* l2 = slow->next;
            slow->next = nullptr;

            l1 = sort_list(l1);
            l2 = sort_list(l2);
            return merge_sorted_list(l1, l2);
        };

        return sort_list(head);
    }
};
