// 430 Flatten a Multilevel Doubly Linked List
// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list

// version: 1; create time: 2019-11-07 20:52:29;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;

        std::stack<Node*> stk;
        stk.push(head);

        Node* pre = nullptr;
        while (!stk.empty()) {
            auto node = stk.top(); stk.pop();
            while (node) {
                if (pre) pre->next = node;
                node->prev = pre;
                pre = node;
                node = node->next;
                if (pre->child) {
                    stk.push(pre->next);
                    stk.push(pre->child);
                    pre->child = nullptr;
                    break;
                }
            }
        }

        return head;
    }
};

//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        function<Node*(Node*)> flatten_helper;
        flatten_helper = [&](Node* head) {
            Node* node = head;
            Node* prev = node;
            while (node) {
                if (node->child) {
                    Node* flatten_head = node->child;
                    Node* flatten_tail = flatten_helper(node->child);
                    Node* next = node->next;
                    
                    node->next = flatten_head;
                    flatten_head->prev = node;

                    flatten_tail->next = next;
                    if (next) {
                        next->prev = flatten_tail;
                    }

                    node->child = nullptr;
                    prev = flatten_tail;
                    node = next;
                } else {
                    prev = node;
                    node = node->next;
                }
            }
            return prev;
        };
        flatten_helper(head);
        return head;
    }
};