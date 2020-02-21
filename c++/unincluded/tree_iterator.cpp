#include "common.hpp"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val = 0, TreeNode* left = nullptr, TreeNode* right = nullptr) :
        val(val), left(left), right(right) {}
};


class InorderIterator {
    private:
        TreeNode* node;
        stack<TreeNode*> stk;

    public:
        InorderIterator(TreeNode* root) : node(root) {}

        bool hasNext() const {
            return node || !stk.empty();
        }

        TreeNode* next() {
            while (node) {
                stk.push(node);
                node = node->left;
            }
            auto ret = stk.top(); stk.pop();
            node = ret->right;
            return ret;
        }
};


enum Direction { Left, Right };

class InorderIterator2 {
    private:
        int depth;
        TreeNode* node;
        vector<TreeNode*> npath;
        vector<Direction> dpath;

        template<typename T>
        void assign(vector<T>& vec, const size_t idx, const T& data) {
            if (vec.size() <= idx) vec.resize(idx + 1);
            vec[idx] = data;
        }

        int findFirst(Direction d) {
            auto tmp = depth;
            while (tmp >= 0 && dpath[tmp] != d) --tmp;
            return tmp;
        }

    public:
        InorderIterator2(TreeNode* root) : depth(0), node(root) {}

        bool hasNext() {
            return npath.empty() || findFirst(Left) != -1;
        }

        TreeNode* next() {
            while (node) {
                assign(npath, depth, node);
                assign(dpath, depth, Left);
                ++depth;
                node = node->left;
            }

            depth = findFirst(Left);

            auto ret = npath[depth];
            dpath[depth] = Right;
            node = ret->right;
            return ret;
        }

        bool hasPrev() {
            return npath.empty() || findFirst(Right) != -1;
        }

        TreeNode* prev() {
            while (node) {
                assign(npath, depth, node);
                assign(dpath, depth, Left);
                ++depth;
                node = node->right;
            }

            depth = findFirst(Right);

            auto ret = npath[depth];
            dpath[depth] = Left;
            node = ret->left;
            return ret;
        }
};

int main() {
    //          e(2)
    //      c(1)     d(3)
    //  b(0)                a(4)
    TreeNode* a = new TreeNode(4);
    TreeNode* b = new TreeNode(0);
    TreeNode* c = new TreeNode(1, b, nullptr);
    TreeNode* d = new TreeNode(3, nullptr, a);
    TreeNode* e = new TreeNode(2, c, d);

    InorderIterator2 iter(e);
    while (iter.hasNext()) {
        cout << iter.next()->val << "\n";
    }
    cout << "#\n";
    while (iter.hasPrev()) {
        cout << iter.prev()->val << "\n";
    }
    return 0;
}