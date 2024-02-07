class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        const int n = grid.size();

        auto encode = [&n](int i, int j)
        {
            return i * n + j;
        };
        auto invalid_idx = [&n](int i, int j)
        {
            return i < 0 || i >= n || j < 0 || j >= n;
        };

        vector<int> parent(n * n, 0);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find_f;
        find_f = [&](int i)
        {
            if (parent[i] != i)
            {
                return parent[i] = find_f(parent[i]);
            }
            return i;
        };

        function<void(int, int)> union_f;
        union_f = [&](int i, int j)
        {
            int pi = find_f(i);
            int pj = find_f(j);
            parent[pj] = parent[pi];
        };

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!grid[i][j])
                    continue;
                constexpr int offsets[2][2] = {{1, 0}, {0, 1}};
                for (int k = 0; k < 2; ++k)
                {
                    int ii = i + offsets[k][0], jj = j + offsets[k][1];
                    if (ii < 0 || ii >= n || jj < 0 || jj >= n || !grid[ii][jj])
                        continue;
                    union_f(encode(i, j), encode(ii, jj));
                }
            }
        }

        int largest_island = 0;
        unordered_map<int, int> island_size;
        for (int k = 0; k < n * n; ++k)
        {
            int p = find_f(k);
            largest_island = max(largest_island, ++island_size[p]);
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j])
                    continue;
                constexpr int offsets[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                unordered_set<int> connected_islands;
                for (int k = 0; k < 4; ++k)
                {
                    int ii = i + offsets[k][0], jj = j + offsets[k][1];
                    if (invalid_idx(ii, jj) || !grid[ii][jj])
                        continue;
                    connected_islands.insert(find_f(encode(ii, jj)));
                }
                int connected_size = 1;
                for (int i : connected_islands)
                {
                    connected_size += island_size[i];
                }
                largest_island = max(largest_island, connected_size);
            }
        }

        return largest_island;
    }
};

//

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        const int n = grid.size();

        vector<int> p(n * n, 0);
        iota(p.begin(), p.end(), 0);

        function<int(int)> find_f;
        find_f = [&](int i)
        {
            if (p[i] != i)
            {
                p[i] = find_f(p[i]);
            }
            return p[i];
        };

        function<void(int, int)> union_f;
        union_f = [&](int i, int j)
        {
            int pi = find_f(i);
            int pj = find_f(j);
            p[pi] = p[pj];
        };

        constexpr int offsets[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!grid[i][j])
                    continue;
                for (int k = 0; k < 4; ++k)
                {
                    int new_i = i + offsets[k][0];
                    int new_j = j + offsets[k][1];
                    if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= n || !grid[new_i][new_j])
                        continue;
                    union_f(i * n + j, new_i * n + new_j);
                }
            }
        }

        int largest_island = 0;
        unordered_map<int, int> union_sizes;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!grid[i][j])
                    continue;
                largest_island = max(largest_island, ++union_sizes[find_f(i * n + j)]);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j])
                    continue;
                unordered_set<int> unions;
                for (int k = 0; k < 4; ++k)
                {
                    int new_i = i + offsets[k][0];
                    int new_j = j + offsets[k][1];
                    if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= n || !grid[new_i][new_j])
                        continue;
                    unions.insert(find_f(new_i * n + new_j));
                }
                int island = 1;
                for (const auto u : unions)
                {
                    island += union_sizes[u];
                }
                largest_island = max(largest_island, island);
            }
        }

        return largest_island;
    }
};
