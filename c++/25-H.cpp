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
    ListNode* reverse(ListNode* cur, int cnt) {
        ListNode* pre = nullptr;
        for (int i = 0; i < cnt; ++i) {
            auto nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        auto pre_head = new ListNode(0);
        pre_head->next = head;

        auto pre = pre_head;
        auto cur = head;
        while (pre) {
            auto test = cur;
            for (int i = 0; i < k; ++i) {
                if (!test) {
                    pre->next = cur;
                    return pre_head->next;
                }
                test = test->next;
            }

            auto new_head = reverse(cur, k);
            pre->next = new_head;
            pre = cur;
            cur = test;
        }

        return pre_head->next;
    }
};