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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stk1;
        stack<int> stk2;

        auto node = l1;
        while (node) {
            stk1.push(node->val);
            node = node->next;
        }
        node = l2;
        while (node) {
            stk2.push(node->val);
            node = node->next;
        }

        ListNode* head = nullptr;
        int carry = 0;
        while (!stk1.empty() || !stk2.empty() || carry) {
            auto lhs = stk1.empty() ? 0 : stk1.top();
            auto rhs = stk2.empty() ? 0 : stk2.top();
            auto sum = lhs + rhs + carry;
            auto node = new ListNode(sum % 10);
            node->next = head;
            head = node;
            carry = sum / 10;
            if (!stk1.empty()) stk1.pop();
            if (!stk2.empty()) stk2.pop();
        }
        return head;
    }
};