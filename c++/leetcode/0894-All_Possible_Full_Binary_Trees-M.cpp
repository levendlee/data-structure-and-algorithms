class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int, vector<TreeNode*>> mem;

        function<vector<TreeNode*>(int n)> build;
        build = [&](int n) -> vector<TreeNode*> {
            if (mem.count(n)) {
              return mem[n];
            }

            if (n == 1) {
                return {new TreeNode(0)};
            }

            vector<TreeNode*> ret;
            for (int i = 1; i <= n - 2; i+= 2) {
                auto left = build(i);
                auto right = build(n - 1 - i);
                for (auto l : left) {
                    for (auto r : right) {
                        TreeNode* node = new TreeNode(0);
                        node->left = l;
                        node->right = r;
                        ret.push_back(node);
                    }
                }
            }

            mem[n] = ret;
            return ret;
        };

        if (!(n & 0x1)) {
            return {};
        } else {
            return build(n);
        }
    }
};
