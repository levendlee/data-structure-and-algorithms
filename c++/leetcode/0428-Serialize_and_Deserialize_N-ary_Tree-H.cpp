// 428 Serialize and Deserialize N-ary Tree
// https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree

// version: 1; create time: 2020-02-06 23:22:25;
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
private:
    void serializeHelper(Node* root, string& s) {
        if (root == nullptr) {
            s += "$";
            return;
        }
        s += to_string(root->val);
        s += "@";
        s += to_string(root->children.size());
        s += "#";
        for (const auto& node : root->children) {
            serializeHelper(node, s);
        }
    }

    Node* deserializeHelper(const string& s, int& i) {
        if (s[i] == '$') {
            ++i;
            return nullptr;
        }

        auto j = s.find('@', i);
        auto val = stoi(s.substr(i, j - i));
        auto k = s.find('#', j + 1);
        auto cnt = stoi(s.substr(j + 1, k - j - 1));
        i = k + 1;

        auto node = new Node(val);
        node->children.resize(cnt);
        for (int t = 0; t < cnt; ++t) {
            node->children[t] = deserializeHelper(s, i);
        }
        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string s;
        serializeHelper(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        int i = 0;
        return deserializeHelper(data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

//

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string s;
        function<void(Node*)> dfs;
        dfs = [&](Node* node) {
            if (!node) {
                s += '$';
                return;
            }
            s += to_string(node->val);
            s += '#';
            for (const auto& child : node->children) {
                dfs(child);
            }
            s += '$';
            return;
        };
        dfs(root);
        return s;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        const int n = data.size();
        int i = 0;

        Node* root = nullptr;
        function<Node*()> dfs;
        dfs = [&]() -> Node* {
            if (data[i] == '$') {
                ++i;
                return nullptr;
            }
            
            int j = i;
            while (isdigit(data[j])) ++j;
            int val = stoi(data.substr(i, j - i));
            i = j + 1;

            Node* node = new Node(val);
            while (i < n && data[i] != '$') {
                node->children.push_back(dfs());
            }
            ++i;
            return node;
        };

        return dfs();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));