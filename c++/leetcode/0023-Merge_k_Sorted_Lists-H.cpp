// 23 Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists

// version: 1; create time: 2019-10-22 20:43:03;
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


// version: 2; create time: 2020-02-20 21:37:15;
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

// 2023/10/23

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* merged_list_prehead = new ListNode();
        ListNode* merged_list = merged_list_prehead;

        const int k = lists.size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k; ++i) {
            if (lists[i]) {
                pq.push({-lists[i]->val, i});
            }
        }

        while (!pq.empty()) {
            auto index = pq.top().second;
            pq.pop();
            merged_list->next = lists[index];
            merged_list = merged_list->next;
            lists[index] = lists[index]->next;
            if (lists[index]) {
                pq.push({-lists[index]->val, index});
            }
        }

        return merged_list_prehead->next;

    }
};
