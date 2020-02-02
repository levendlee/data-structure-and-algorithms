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