#include <string>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

struct TreeNode {
    string name;
    string str;
    TreeNode* left;
    TreeNode* right;
};

struct Match {
    vector<TreeNode*> nodes;
    int startIndex;
    Match(const vector<TreeNode*>& nodes, int startIndex) : nodes(nodes), startIndex(startIndex) {}
};

struct MatchProcess {
    Match match;
    int index;
};

void inOrderSearch(TreeNode* root,
                   const string& s,
                   vector<MatchProcess>& matching,
                   vector<Match>& matched) {
    if (!root) return;
    if (!root->left && !root->right) {
        const auto& str = root->str;
        const int n = str.size();

        for (auto& m : matching) {
            m.match.nodes.push_back(root);
        }

        for (int i = 0; i < n; ++i) {
            vector<MatchProcess> n_matching;
            for (auto& m : matching) {
                if (str[i] == s[m.index]) {
                    if (++m.index == s.size()) {
                        matched.push_back(m.match);
                    } else {
                        n_matching.push_back(m);
                    }
                }
            }
            if (str[i] == s[0]) {
                Match match({root}, i);
                if (s.size() > 1) {
                    MatchProcess match_process{match, 1};
                    n_matching.push_back(match_process);
                } else {
                    matched.push_back(match);
                }
            }
            matching = move(n_matching);
        }

    } else {
        inOrderSearch(root->left, s, matching, matched);
        inOrderSearch(root->right, s, matching, matched);
    }
}

vector<Match> searchStringInTreeLeaves(TreeNode* root, const string& s) {
    vector<MatchProcess> matching;
    vector<Match> matched;
    inOrderSearch(root, s, matching, matched);
    return matched;
};

int main() {
    TreeNode leave_a{ "a", "abc", nullptr, nullptr };
    TreeNode leave_b{ "b", "def", nullptr, nullptr };
    TreeNode leave_c{ "c", "abbc", nullptr, nullptr };
    TreeNode leave_d{ "d", "eggf", nullptr, nullptr };
    TreeNode node_e{ "e", "", &leave_a, &leave_b };
    TreeNode node_f{ "f", "", &leave_c, &leave_d };
    TreeNode node_g{ "g", "", &node_e, &node_f};



    auto query = [&](const string& s) {
        cout << "Query: " << s << "\n";
        auto res = searchStringInTreeLeaves(&node_g, s);
        for (auto& m : res) {
            cout << "Match : (";
            for (auto& n : m.nodes) cout << n->name << ",";
            cout << ")," << m.startIndex << "\n";
        }
    };

    query("bc");
    query("b");
    query("ce");
    query("bcdefa");
    return 0;
}
