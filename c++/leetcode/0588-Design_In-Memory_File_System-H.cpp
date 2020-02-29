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
