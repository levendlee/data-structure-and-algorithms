class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* r_node = nullptr;
        ListNode* node = head;
        ListNode* n_node;
        
        while (node) {
            n_node = node->next;
            node->next = r_node;
            r_node = node;
            node = n_node;
        }

        return r_node;
    }

    int pairSum(ListNode* head) {
        ListNode *fast = head, *slow = head, *pre;
        
        // 1. Find middle.
        while (fast && fast->next) {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }

        // 2. Reverse first half.
        auto l2 = slow;
        pre->next = nullptr;
        auto l1 = reverseList(head);

        // 3. Pair up.
        int max_sum = INT_MIN;
        while (l1 && l2) {
            max_sum = max(max_sum, l1->val + l2->val);
            l1 = l1->next;
            l2 = l2->next;
        }
        return max_sum;
    }
};
