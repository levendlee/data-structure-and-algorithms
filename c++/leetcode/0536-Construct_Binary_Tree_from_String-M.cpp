/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s.empty()) {
            return nullptr;
        }

        const int n = s.size();
        int i = 0;
        auto read_int = [&]() {
            int sign = 1;
            if (s[i] == '-') {
                sign = -1;
                ++i;
            } else if (s[i] == '+') {
                sign = 1;
                ++i;
            }
            int j = i;
            while (isdigit(s[j])) ++j;
            int num = stoi(s.substr(i, j - i));
            i = j;
            return sign * num;
        };

        TreeNode* root = new TreeNode(read_int());

        stack<TreeNode*> stk;
        stk.push(root);

        while (i < n) {
            if (s[i] == '(') {
                ++i;
                TreeNode* node = new TreeNode(read_int());
                if (stk.top()->left) {
                    stk.top()->right = node;
                } else {
                    stk.top()->left = node;
                }
                stk.push(node);
            } else {
                ++i;
                stk.pop();
            }
        }

        return root;
    }
};