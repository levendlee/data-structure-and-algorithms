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
