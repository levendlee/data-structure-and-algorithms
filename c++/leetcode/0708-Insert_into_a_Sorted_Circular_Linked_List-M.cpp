// 708 Insert into a Sorted Circular Linked List
// https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list

// version: 1; create time: 2019-12-25 15:49:43;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* new_node = new Node(insertVal);

        if (head == nullptr) {
            new_node->next = new_node;
            head = new_node;
        } else {
            Node* node = head;
            while (true) {
                // In the middle || At the beginning / ending || Traversed and still didn't find
                if (node->val <= insertVal && node->next->val >= insertVal
                    || (node->val > node->next->val) && (node->val <= insertVal || node->next->val >= insertVal)
                    || (node->next == head)) {
                    Node* tmp = node->next;
                    node->next = new_node;
                    new_node->next = tmp;
                    break;
                }
                node = node->next;
            }
        }
        return head;
    }
};
