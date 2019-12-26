/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    /*
private:
    int cnt;
    std::unordered_map<int, int> p_;

    void union_(int a, int b) {
        if (!p_.count(a) || !p_.count(b)) {
            return;
        }
        auto pa = find_(a);
        auto pb = find_(b);
        if (pa != pb) {
            --cnt;
            p_[pa] = pb;
        }
    }

    int find_(int a) {
        auto pa = p_[a];
        if (pa != a) {
            p_[a] = find_(pa);
        }
        return p_[a];
    }

public:
    int numComponents(ListNode* head, vector<int>& G) {
        cnt = G.size();
        for (const auto& g : G) {
            p_[g] = g;
        }

        ListNode* node = head;
        if (!node) {
            return cnt;
        }

        while (node->next) {
            union_(node->val, node->next->val);
            node = node->next;
        }
        return cnt;
    }
    */

public:
    int numComponents(ListNode* head, vector<int>& G) {
        std::unordered_set<int> hashmap;
        for (const auto& g : G) {
            hashmap.insert(g);
        }

        int cnt = 0;
        bool continuous = false;
        ListNode* node = head;
        while (node) {
             if (hashmap.count(node->val)) {
                 if (!continuous) {
                     continuous = true;
                     ++cnt;
                 }
                 hashmap.erase(node->val);
             } else {
                 continuous = false;
             }
             node = node->next;
        }

        return cnt += hashmap.size();
    }

};