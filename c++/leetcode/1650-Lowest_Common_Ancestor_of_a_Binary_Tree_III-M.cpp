class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> p_ancestors;

        while (p) {
            p_ancestors.insert(p);
            p = p->parent;
        }

        while (q) {
            if (p_ancestors.count(q)) return q;
            q = q->parent;
        }

        return nullptr;
    }
};
