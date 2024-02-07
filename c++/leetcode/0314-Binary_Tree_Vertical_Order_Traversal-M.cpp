// 314 Binary Tree Vertical Order Traversal
// https://leetcode.com/problems/binary-tree-vertical-order-traversal

// version: 2; create time: 2020-02-21 19:06:23;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> verticalOrder(TreeNode *root)
    {
        if (!root)
            return {};

        vector<vector<int>> lvec, rvec;
        queue<pair<TreeNode *, int>> bfs;
        bfs.push({root, 0});
        while (!bfs.empty())
        {
            auto node = bfs.front().first;
            auto shift = bfs.front().second;
            bfs.pop();
            if (shift >= 0)
            {
                if (rvec.size() == shift)
                    rvec.resize(shift + 1);
                rvec[shift].push_back(node->val);
            }
            else
            {
                if (lvec.size() == -shift - 1)
                    lvec.resize(-shift);
                lvec[-shift - 1].push_back(node->val);
            }
            if (node->left)
                bfs.push({node->left, shift - 1});
            if (node->right)
                bfs.push({node->right, shift + 1});
        }

        reverse(lvec.begin(), lvec.end());
        for (auto &vec : rvec)
        {
            lvec.push_back(move(vec));
        }
        return lvec;
    }
};

// version: 1; create time: 2020-01-18 18:24:49;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
    vector<vector<int>> left_;
    vector<vector<int>> right_;

public:
    void traversal(TreeNode *root)
    {
        if (!root)
            return;

        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            auto node = q.front().first;
            auto idx = q.front().second;
            q.pop();

            if (idx >= 0)
            {
                if (right_.size() <= idx)
                {
                    right_.push_back({});
                }
                right_[idx].push_back(node->val);
            }
            else
            {
                if (left_.size() < -idx)
                {
                    left_.push_back({});
                }
                left_[-idx - 1].push_back(node->val);
            }
            if (node->left)
                q.push({node->left, idx - 1});
            if (node->right)
                q.push({node->right, idx + 1});
        }
    }

    vector<vector<int>> verticalOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        left_.clear();
        right_.clear();
        traversal(root);

        std::reverse(left_.begin(), left_.end());
        for (auto &vec : left_)
        {
            res.emplace_back(std::move(vec));
        }
        for (auto &vec : right_)
        {
            res.emplace_back(std::move(vec));
        }
        return res;
    }
};

//

class Solution
{
public:
    vector<vector<int>> verticalOrder(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }

        vector<vector<int>> l_cols, r_cols;

        queue<pair<TreeNode *, int>> bfs;
        bfs.push({root, 0});

        while (!bfs.empty())
        {
            int search_size = bfs.size();
            for (int k = 0; k < search_size; ++k)
            {
                auto [node, i] = bfs.front();
                bfs.pop();

                vector<vector<int>> &cols = i >= 0 ? r_cols : l_cols;
                int idx = i >= 0 ? i : -i - 1;
                if (cols.size() < idx + 1)
                {
                    cols.push_back({node->val});
                }
                else
                {
                    cols[idx].push_back(node->val);
                }
                if (node->left)
                {
                    bfs.push({node->left, i - 1});
                }
                if (node->right)
                {
                    bfs.push({node->right, i + 1});
                }
            }
        }

        reverse(l_cols.begin(), l_cols.end());
        l_cols.insert(l_cols.end(), r_cols.begin(), r_cols.end());
        return l_cols;
    }
};

//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> verticalOrder(TreeNode *root)
    {
        if (!root)
            return {};

        unordered_map<int, vector<int>> cols;

        queue<pair<TreeNode *, int>> bfs;
        bfs.push({root, 0});

        int min_col = 0, max_col = 0;

        while (!bfs.empty())
        {
            auto [node, i] = bfs.front();
            bfs.pop();
            min_col = min(i, min_col);
            max_col = max(i, max_col);
            cols[i].push_back(node->val);
            if (node->left)
                bfs.push({node->left, i - 1});
            if (node->right)
                bfs.push({node->right, i + 1});
        }

        vector<vector<int>> res;
        for (int i = min_col; i <= max_col; ++i)
        {
            res.emplace_back(move(cols[i]));
        }
        return res;
    }
};