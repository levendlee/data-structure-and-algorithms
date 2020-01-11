/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serializeHelper(TreeNode* root, string& str) {
        if (root == nullptr) {
            return;
        };
        str += std::to_string(root->val);
        str += 'L';
        serializeHelper(root->left, str);
        str += 'R';
        serializeHelper(root->right, str);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialized;
        serializeHelper(root, serialized);
        return serialized;
    }

    void deserializeHelper(TreeNode*& root, string& str, int& idx) {
        if (!isdigit(str[idx])) {
            root = nullptr;
        } else {
            auto next_idx = str.find('L', idx);
            auto val = std::stoi(str.substr(idx, next_idx - idx));
            root = new TreeNode(val);
            idx = next_idx + 1;
            deserializeHelper(root->left, str, idx);
            ++idx;
            deserializeHelper(root->right, str, idx);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root;
        int idx = 0;
        deserializeHelper(root, data, idx);
        return root;
    }
};
