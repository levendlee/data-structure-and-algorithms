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
    ListNode* mergeHelper(vector<ListNode*>& lists, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        if (start == end) {
            return lists[start];
        }

        int mid = start + (end - start) / 2;
        auto left = mergeHelper(lists, start, mid);
        auto right = mergeHelper(lists, mid+1, end);

        ListNode* phead = new ListNode(0);
        ListNode* node = phead;

        while(left != nullptr || right != nullptr) {
            if ((right == nullptr) ||
                ((left != nullptr) && (right != nullptr) &&
                 (left->val < right->val))) {
                node->next = left;
                node = node->next;
                left = left->next;
            } else {
                node->next = right;
                node = node->next;
                right = right->next;
            }
        }
        return phead->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeHelper(lists, 0, lists.size() - 1);
    }
};