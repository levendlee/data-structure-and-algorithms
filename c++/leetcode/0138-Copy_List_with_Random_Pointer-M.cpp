// 138 Copy List with Random Pointer
// https://leetcode.com/problems/copy-list-with-random-pointer

// version: 1; create time: 2019-12-30 11:34:15;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* getCopyNode(std::unordered_map<Node*, Node*>& copies, 
                      Node* node) {
        if (copies.count(node) == 0){
            copies[node] = new Node(node->val);
        }
        return copies[node];
    }
    
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> copies;
        copies[nullptr] = nullptr;
        Node* copy_head = getCopyNode(copies, head);
        Node* copy_node = copy_head;
        Node* node = head;
        while (node) {
            copy_node->next = getCopyNode(copies, node->next);
            copy_node->random = getCopyNode(copies, node->random);
            copy_node = copy_node->next;
            node = node->next;
        }
        return copy_head;
    }
};

// 2023/10/21
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        unordered_map<Node*, Node*> originals_to_copies;
        Node* cur = head;
        while (cur) {
            originals_to_copies[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            Node* copy = originals_to_copies[cur];
            copy->next = originals_to_copies[cur->next];
            copy->random = originals_to_copies[cur->random];
            cur = cur->next;
        }
        return originals_to_copies[head];
    }
};
