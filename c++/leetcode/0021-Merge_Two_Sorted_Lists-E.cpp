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

//

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* pre_head = new ListNode(0);
        ListNode* node = pre_head;

        while (list1 || list2) {
            if (!list2 || list1 && list1->val < list2->val) {
                node->next = list1;
                node = node->next;
                list1 = list1->next;
            } else {
                node->next = list2;
                node = node->next;
                list2 = list2->next;
            }
        }

        return pre_head->next;
    }
};
