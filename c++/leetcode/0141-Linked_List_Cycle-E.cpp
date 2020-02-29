// 141 Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle

// version: 1; create time: 2020-02-01 23:43:37;
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
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        auto fast = head->next->next;
        auto slow = head;
        while (fast != slow) {
            if (!fast || !fast->next) return false;
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};
