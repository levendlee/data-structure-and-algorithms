/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        auto reverse_list = [](ListNode* head) {
            if (!head || !head->next) return head;

            ListNode* pre = nullptr;
            ListNode* cur = head;
            ListNode* nex;
            while (cur) {
                nex = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nex;
            }
            return pre;
        };

        // 1->2->3
        // fast move to 3
        // slow move to 2
        // 1->2->3->4
        // fast move to nullptr
        // slow move to 3
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // odd case
        if (fast) {
            slow = slow->next;
        }
        
        auto node0 = head;
        auto node1 = reverse_list(slow);

        while (node0 && node1) {
            if (node0->val != node1->val) return false;
            node0 = node0->next;
            node1 = node1->next;
        }
        return true;
    }
};