class Codec {
public:

    int readNum(const string& s, int& pos) {
        int i = pos, j = pos, n = s.size();
        int sign = 1;
        if (s[j] == '-') {
            sign = -1;
            ++j;
        } else if (s[j] == '+') {
            sign = 1;
            ++j;
        }
        while (j < n && isdigit(s[j])) ++j;
        int num = stoi(s.substr(i, j - i));
        pos = j;
        return num;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialized;
        function<void(TreeNode*)> preorder;
        preorder = [&](TreeNode* node) {
            if (!node) {
                serialized += '#';
                return;
            }
            serialized += to_string(node->val);
            serialized += '#';
            preorder(node->left);
            preorder(node->right);
        };
        preorder(root);
        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root;
        int pos = 0;
        function<void(TreeNode*&)> preorder;
        preorder = [&](TreeNode*& node) {
            if (data[pos] == '#') {
                ++pos;
                node = nullptr;
                return;
            }
            int num = readNum(data, pos);
            ++pos;
            node = new TreeNode(num);
            preorder(node->left);
            preorder(node->right);
        };
        preorder(root);
        return root;
    }
};
