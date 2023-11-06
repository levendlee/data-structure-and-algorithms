// 25 Reverse Nodes in k-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group

// version: 1; create time: 2020-01-18 12:07:39;
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

//

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* pre_head = new ListNode();
        pre_head->next = head;

        ListNode* pre = pre_head;
        ListNode* cur = head;

        while (cur) {
            ListNode* n_start = cur;
            ListNode* n_pre = pre;

            for (int i = 0; i < k; ++i) {
                if (!cur) goto resolve;
                pre = cur;
                cur = cur->next;
            }

            ListNode* n_end = pre;
            ListNode* n_post = cur;

            cur = n_start;
            pre = n_pre;
            while (cur != n_post) {
                auto tmp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = tmp;
            }

            n_pre->next = n_end;
            n_start->next = n_post;

            pre = n_start;
            cur = n_post;
        }

        resolve:
        return pre_head->next;
    }
};
