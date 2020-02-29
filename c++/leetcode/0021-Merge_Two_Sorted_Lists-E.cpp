// 21 Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists

// version: 1; create time: 2019-12-30 11:34:15;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* const preHead = new ListNode(0);
        ListNode* node = preHead;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr || l2 != nullptr && l2->val < l1->val) {
                node->next = l2;
                l2 = l2->next;
            } else {
                node->next = l1;
                l1 = l1->next;
            }
            node = node->next;
        }
        return preHead->next;
    }
};
