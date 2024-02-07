class Solution
{
public:
    int longestPath(vector<int> &parent, string s)
    {
        if (s.empty())
            return 0;

        unordered_map<int, vector<int>> parent2children;
        for (int i = 0; i < parent.size(); ++i)
        {
            parent2children[parent[i]].push_back(i);
        }

        int longest_path = 0;
        function<int(int)> dfs;
        dfs = [&](int node) -> int
        {
            auto iter = parent2children.find(node);

            if (iter != parent2children.end())
            {
                int longest_subpath_0 = 0;
                int longest_subpath_1 = 0;
                for (const int child : iter->second)
                {
                    int subpath = dfs(child);
                    longest_path = max(longest_path, subpath);
                    if (node >= 0 && s[node] == s[child])
                        continue;
                    if (longest_subpath_0 <= subpath)
                    {
                        longest_subpath_1 = longest_subpath_0;
                        longest_subpath_0 = subpath;
                    }
                    else if (longest_subpath_1 <= subpath)
                    {
                        longest_subpath_1 = subpath;
                    }
                }
                longest_path = max(longest_path, longest_subpath_0 + longest_subpath_1 + (node >= 0));
                return longest_subpath_0 + 1;
            }
            return 1;
        };
        dfs(-1);

        return longest_path;
    }
};

//

class Solution
{
public:
    int longestPath(vector<int> &parent, string s)
    {
        if (s.empty())
            return 0;

        unordered_map<int, vector<int>> parent2children;
        for (int i = 0; i < parent.size(); ++i)
        {
            parent2children[parent[i]].push_back(i);
        }

        int longest_path = 0;

        function<int(int)> dfs;
        dfs = [&](int i)
        {
            std::priority_queue<int> pq;
            for (const auto &child : parent2children[i])
            {
                int subpath = dfs(child);
                if (i != -1 && s[i] == s[child])
                    continue;
                pq.push(-subpath);
                if (pq.size() > 2)
                {
                    pq.pop();
                }
            }
            longest_path = max(longest_path, 1);
            if (pq.empty())
                return 1;
            int p0 = -pq.top();
            pq.pop();
            longest_path = max(longest_path, p0 + (i != -1));
            if (pq.empty())
                return p0 + 1;
            int p1 = -pq.top();
            pq.pop();
            longest_path = max(longest_path, p0 + p1 + (i != -1));
            return p1 + 1;
        };

        dfs(-1);
        return longest_path;
    }
};