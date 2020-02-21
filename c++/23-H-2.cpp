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
    // Current solution:
    // K list, Avg size N elements
    // Time Complexity: O(NKlogK)
    // Space Complexity: O(logK)
    // Priority queue solution:
    // Time Complexity: O(NKlogK)
    // Space Complexity: O(K)
    ListNode* mergeList(vector<ListNode*>& lists, int lo, int hi) {
        if (lo > hi) return nullptr;
        if (lo == hi) return lists[lo];

        int mid = lo + (hi - lo) / 2;
        auto left = mergeList(lists, lo, mid);
        auto right = mergeList(lists, mid + 1, hi);

        auto pre_head = new ListNode(0);
        auto node = pre_head;
        while (left || right) {
            if (!right || left && (left->val < right->val)) {
                node->next = left;
                left = left->next;
            } else {
                node->next = right;
                right = right->next;
            }
            node = node->next;
        }
        auto head = pre_head->next;
        delete pre_head;
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeList(lists, 0, lists.size() - 1);
    }
};