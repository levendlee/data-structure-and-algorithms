class Solution {
public:
    Node* connect(Node* root) {
        std::unordered_map<int, Node*> level_to_tail;

        std::function<void(Node*, int)> traverse;
        traverse = [&](Node* node, int level) {
            if (!node) return;

            if (level_to_tail.count(level)) {
                level_to_tail[level]->next = node;
            }
            level_to_tail[level] = node;

            traverse(node->left, level + 1);
            traverse(node->right, level + 1);
        };

        traverse(root, 0);
        return root;
    }
};
