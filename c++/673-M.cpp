class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return n;

        vector<vector<int>> dp(n);
        int total_max_len = 0;
        int total_max_cnt = 0;
        for (int i = 0; i < n; ++i) {
            int max_len = 1;
            int max_cnt = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] >= nums[i]) continue;
                if (dp[j][0] + 1 > max_len) {
                    max_len = dp[j][0] + 1;
                    max_cnt = dp[j][1];
                } else if (dp[j][0] + 1 == max_len) {
                    max_cnt += dp[j][1];
                }
            }
            dp[i] = {max_len, max_cnt};

            if (max_len > total_max_len) {
                total_max_len = max_len;
                total_max_cnt = max_cnt;
            } else if (max_len == total_max_len) {
                total_max_cnt += max_cnt;
            }
        }

        return total_max_cnt;
    }
};

struct Node {
    int range_left;
    int range_right;
    pair<int, int> max_len_cnt;
    Node* node_left;
    Node* node_right;

    Node(int left, int right) : range_left(left), range_right(right), node_left(nullptr), node_right(nullptr) {}
    int range_mid() const {
        if (range_left + 1 == range_right)
            return range_left;
        else
            return (range_left + range_right) / 2;
    }
    Node* left() {
        if (!node_left) node_left = new Node(range_left, range_mid());
        return node_left;
    }
    Node* right() {
        if (!node_right) node_right = new Node(range_mid() + 1, range_right);
        return node_right;
    }
};


// Segment Tree
class Solution {
private:
    pair<int, int> merge(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        if (lhs.first == rhs.first) {
            if (lhs.first == 0) {
                return {0, 1};
            } else {
                return {lhs.first, lhs.second + rhs.second};
            }
        } else {
            return std::max(lhs, rhs);
        }
    }

    void update(Node* node, int key, const pair<int, int>& len_cnt) {
        if (node->range_right >= key) {
            if (node->range_left == node->range_right) {
                node->max_len_cnt = merge(node->max_len_cnt, len_cnt);
            } else {
                if (node->range_mid() >= key && node->left()->range_right != node->range_right) {
                    update(node->left(), key, len_cnt);
                } else {
                    update(node->right(), key, len_cnt);
                }
                node->max_len_cnt = merge(node->left()->max_len_cnt, node->right()->max_len_cnt);
            }
        }
    }

    pair<int, int> query(Node* node, int upper) {
        if (node->range_right <= upper) {
            return node->max_len_cnt;
        } else if (node->range_left > upper) {
            return {0, 1};
        } else {
            auto lhs = query(node->left(), upper);
            auto rhs = query(node->right(), upper);
            return merge(lhs, rhs);
        }
    }

public:
    int findNumberOfLIS(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return n;

        const auto ss = *std::min_element(nums.begin(), nums.end());
        const auto se = *std::max_element(nums.begin(), nums.end());
        Node* node = new Node(ss, se);
        for (int i = 0; i < n; ++i) {
            auto res = query(node, nums[i] - 1);
            ++res.first;
            update(node, nums[i], res);
        }
        return node->max_len_cnt.second;
    }
};