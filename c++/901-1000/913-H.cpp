#define MWIN 1
#define CWIN 2
#define DRAW 0

#define MMOVE 0
#define CMOVE 1

class Solution {
    /* Top-Down solution. TLE
private:
    vector<vector<int8_t>> mem_;
    vector<vector<int>> mem2_;

    int dfs(const vector<vector<int>>& graph, int mouse, int cat, bool mouse_turn) {
        if (mouse == 0) {
            return MOUSE_WIN;
        }
        if (cat == mouse) {
            return CAT_WIN;
        }
        int8_t mask = 1 << mouse_turn;
        if (mem_[cat][mouse] & mask) {
            return DRAW;
        }
        mem_[cat][mouse] |= mask;

        int result;
        if (mouse_turn) {
            result = CAT_WIN;
            for (const auto& next : graph[mouse]) {
                //if (next == mouse) continue;
                auto status = dfs(graph, next, cat, !mouse_turn);
                if (status == MOUSE_WIN) {
                    result = MOUSE_WIN;
                    break;
                }
                if (status == DRAW) {
                    result = DRAW;
                }
            }
        } else {
            result = MOUSE_WIN;
            for (const auto& next : graph[cat]) {
                //if (next == cat) continue;
                if (next == 0) continue;
                auto status = dfs(graph, mouse, next, !mouse_turn);
                if (status == CAT_WIN) {
                    result = CAT_WIN;
                    break;
                }
                if (status == DRAW) {
                    result = DRAW;
                }
            }
        }
        mem_[cat][mouse] ^= mask;
        return result;
    }

public:
    int catMouseGame(vector<vector<int>>& graph) {
        const int n = graph.size();
        mem_ = vector<vector<int8_t>>(n, vector<int8_t>(n, 0));
        return dfs(graph, 1, 2, true);
    }
    */

private:
    unordered_map<int, int> color_;
    unordered_map<int, int> outdegree_;

public:
    struct Node {
        int cat;
        int mouse;
        bool move;
        Node(int cat, int mouse, bool move): cat(cat), mouse(mouse), move(move) {}
    };

    int& color(int cat, int mouse, int move) {
        return color_[(cat << 7) | (mouse << 1) | move];
    }
    int& color(Node& node) {
        return color(node.cat, node.mouse, node.move);
    }

    int& outdegree(int cat, int mouse, int move) {
        return outdegree_[(cat << 7) | (mouse << 1) | move];
    }
    int& outdegree(Node& node) {
        return outdegree(node.cat, node.mouse, node.move);
    }

    // Bottom-Up solution
    int catMouseGame(vector<vector<int>>& graph) {
        const int n = graph.size();

        for (int i = 1; i < n; ++i) {   // cat
            for (int j = 0; j < n; ++j) {  // mouse
                outdegree(i, j, MMOVE) = graph[j].size();
                outdegree(i, j, CMOVE) = graph[i].size();

                auto& out = outdegree(i, j, CMOVE);
                for (auto& k : graph[i]) {
                    out -= k == 0;
                }
            }
        }

        std::queue<Node> q;
        for (int i = 1; i < n; ++i) {
            for (int m = 0; m < 2; ++m) {
                color(i, i, m) = CWIN;
                q.emplace(i, i, m);
                color(i, 0, m) = MWIN;
                q.emplace(i, 0, m);
            }
        }

        while (!q.empty()) {
            auto node = q.front(); q.pop();
            auto cur_color = color(node);

            if (node.cat == 2 && node.mouse == 1 && node.move == MMOVE) {
                return cur_color;
            }

            int pre_move = (node.move == MMOVE) ? CMOVE : MMOVE;
            for (auto& prev: graph[pre_move == CMOVE ? node.cat : node.mouse]) {
                int pre_cat = pre_move == CMOVE ? prev : node.cat;
                int pre_mouse = pre_move == CMOVE ? node.mouse : prev;
                if (pre_cat == 0) continue;
                Node pnode(pre_cat, pre_mouse, pre_move);
                if (color(pnode) != DRAW) continue;
                if (cur_color == CWIN && pre_move == CMOVE ||
                    cur_color == MWIN && pre_move == MMOVE ||
                    --outdegree(pnode) == 0) {
                    color(pnode) = cur_color;
                    q.push(pnode);
                }
            }
        }
        return color(2, 1, MMOVE);
    }
};