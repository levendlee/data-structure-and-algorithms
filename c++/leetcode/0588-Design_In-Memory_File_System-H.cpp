// 588 Design In-Memory File System
// https://leetcode.com/problems/design-in-memory-file-system

// version: 1; create time: 2020-01-06 23:37:22;
struct FSNode {
    bool isfile;
    string name;
    string content;
    map<string, FSNode*> subdir;

    FSNode(const string& name) : isfile(false), name(name) {}

    FSNode* getSubdir(const string& name) {
        if (!subdir.count(name)) {
            subdir[name] = new FSNode(name);
        }
        return subdir[name];
    }
    bool hasSubdir(const string& name) {
        return subdir[name];
    }
};

class FileSystem {
private:
    FSNode* root_;

    FSNode* mkdir_and_cd(const string& path) {
        const int n = path.size();
        int idx = 1, next_idx;

        auto node = root_;
        while (idx < n) {
            next_idx = path.find('/', idx);
            //auto dir = path.substr(idx, next_idx - idx);
            node = node->getSubdir(path.substr(idx, next_idx - idx));
            if (next_idx == string::npos) break;
            idx = next_idx + 1;
        }
        return node;
    }

public:
    FileSystem() : root_(new FSNode("")) {

    }

    vector<string> ls(string path) {
        auto node = mkdir_and_cd(path);
        if (node->isfile) {
            return {node->name};
        }
        vector<string> res;
        for (const auto& p : node->subdir) {
            res.push_back(p.first);
        }
        return res;
    }

    void mkdir(string path) {
        mkdir_and_cd(path);
    }

    void addContentToFile(string filePath, string content) {
        auto node = mkdir_and_cd(filePath);
        node->isfile = true;
        node->content += content;
    }

    string readContentFromFile(string filePath) {
        auto node = mkdir_and_cd(filePath);
        return node->content;
    }
};

//

struct FSNode {
    string name;
    string content;
    map<string, FSNode*> children;

    FSNode(const string& name) : name(name) {};
};

vector<string> SplitPath(const string& path) {
    vector<string> res;
    int n = path.size();
    int i = 0;
    while (i < n) {
        while (i < n && path[i] == '/') ++i;
        int j = path.find('/', i);
        if (j == string::npos) j = n;
        if (j - i > 0) {
            res.push_back(path.substr(i, j - i));
        }
        i = j + 1;
    }
    return res;
}

class FileSystem {
public:
    FileSystem() {
        root_ = new FSNode("(root)");
    }
    
    vector<string> ls(string path) {
        FSNode* node = getNode(path);
        if (!node->content.empty()) {
            return {node->name};
        }
        vector<string> key_view;
        for (const auto& [k, v] : node->children) {
            key_view.push_back(k);
        }
        return key_view;
    }
    
    void mkdir(string path) {
        getNode(path);
    }
    
    void addContentToFile(string filePath, string content) {
        getNode(filePath)->content += content;
    }
    
    string readContentFromFile(string filePath) {
        return getNode(filePath)->content;
    }

private:
    FSNode* getNode(string filePath) {
        FSNode* node = root_;
        for (const auto& substr: SplitPath(filePath)) {
            if (!node->children[substr]) {
                node->children[substr] = new FSNode(substr);
            }
            node = node->children[substr];
        }
        return node;
    }

    FSNode* root_;
};