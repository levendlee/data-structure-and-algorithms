// 206 Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list

// version: 1; create time: 2020-01-12 12:05:27;
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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        auto pre = head, cur = head->next;
        pre->next = nullptr;
        while (cur) {
            auto tmp = cur->next;   // tmp is the 3rd
            cur->next = pre;        // 2nd points 1st
            pre = cur;              // 2nd become 1st
            cur = tmp;              // 3rd become 2nd
        }
        return pre;
    }
};

//

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* reverse_node = nullptr;
        ListNode* node = head;
        ListNode* next_node;

        while (node) {
            next_node = node->next;
            node->next = reverse_node;
            reverse_node = node;
            node = next_node;
        }

        return reverse_node;
    }
};
