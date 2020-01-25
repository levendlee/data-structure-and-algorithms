struct Node {
    int min;
    int max;
    int val;
    Node* left_;
    Node* right_;

    Node(int min, int max, int val = 0) : min(min), max(max), val(val), left_(nullptr), right_(nullptr) {}
    int mid() const { return (min + max) / 2; }
    Node* left() {
        if (!left_) left_ = new Node(min, mid());
        return left_;
    }
    Node* right() {
        if (!right_) right_ = new Node(mid() + 1, max);
        return right_;
    }
};


class Solution {
private:
    void update(Node* node, int begin, int end, int height) {
        if (node->min > node->max) {
            return;
        } else if (node->min > end || node->max < begin) {
            return;
        } else {
            node->val = std::max(node->val, height);
            if (node->min == node->max) return;
            update(node->left(), begin, end, height);
            update(node->right(), begin, end, height);
        }
    }

    int query(Node* node, int begin, int end) {
        if (node->min > end || node->max < begin) {
            return 0;
        } else if (begin <= node->min && node->max <= end) {
            return node->val;
        } else {
            return std::max(query(node->left(), begin, end), query(node->right(), begin, end));
        }
    }

public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        set<int> points;
        for (const auto& pos : positions) {
            points.insert(pos[0]);
            points.insert(pos[0] + pos[1]);
        }

        const int n = points.size();
        unordered_map<int, int> compression;
        int i = 0;
        for (const auto& p : points) {
            compression[p] = i++;
        }

        vector<int> max_heights;
        int cur_max_h = 0;
        Node* node = new Node(0, n - 1);
        for (const auto& pos : positions) {
            const auto begin = compression[pos[0]];
            const auto end = compression[pos[0] + pos[1]];
            auto height = query(node, begin, end - 1);
            update(node, begin, end - 1, height + pos[1]);
            cur_max_h = std::max(cur_max_h, height + pos[1]);
            max_heights.push_back(cur_max_h);
        }

        return max_heights;
    }
};