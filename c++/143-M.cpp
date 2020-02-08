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