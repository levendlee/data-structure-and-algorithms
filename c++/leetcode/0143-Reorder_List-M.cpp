// 143 Reorder List
// https://leetcode.com/problems/reorder-list

// version: 1; create time: 2020-02-10 13:39:06;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        auto node = head;
        auto pre = node, cur = node->next;
        pre->next = nullptr;
        while (cur) {
            auto nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }

    ListNode* mergeList(ListNode* head1, ListNode* head2) {
        auto pre_head = new ListNode(0);
        auto node = pre_head;
        while (head1 || head2) {
            auto nex1 = head1 ? head1->next : nullptr;
            auto nex2 = head2 ? head2->next : nullptr;
            if (head1) node = (node->next = head1);
            if (head2) node = (node->next = head2);
            head1 = nex1;
            head2 = nex2;
        }
        return pre_head->next;
    }

public:
    void reorderList(ListNode* head) {
        auto node = head;
        int size = 0;
        while (node) {
            node = node->next;
            ++size;
        }
        if (size <= 1) return;

        int half = size / 2;
        node = head;
        while (half--) {
            node = node->next;
        }

        auto nhead = node->next;
        node->next = nullptr;

        nhead = reverseList(nhead);
        head = mergeList(head, nhead);
    }
};

// Redo
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;
        auto pre = head, cur = head->next;
        pre->next = nullptr;
        while (cur) {
            auto nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        auto pre_head = new ListNode(0);
        auto pre = pre_head;
        auto node1 = head1, node2 = head2;
        while (node1 || node2) {
            if (node1) {
                auto tmp = node1;
                node1 = node1->next;
                pre = pre->next = tmp;
            }
            if (node2) {
                auto tmp = node2;
                node2 = node2->next;
                pre = pre->next = tmp;
            }
        }
        return pre_head->next;
    }

public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        auto fast = head;
        auto slow = head;
        auto pre = head;
        // 1, 2 -> fast is nullptr, slow is 2
        // 1, 2, 3 -> fast is 3, slow is 2
        // 1, 2, 3, 4 -> fast is nullptr, slow is 3
        while (fast && fast->next) {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = nullptr;
        slow = reverse(slow);
        head = merge(head, slow);
    }
};
