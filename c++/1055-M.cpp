class Solution {
public:
    int shortestWay(string source, string target) {
        const int n = source.size();
        const int m = target.size();

        int starts[26];
        for (int i = 0; i < 26; ++i) {
            starts[i] = INT_MAX;
        }
        for (int i = 0; i < n; ++i) {
            int idx = source[i] - 'a';
            starts[idx] = std::min(starts[idx], i);
        }

        std::priority_queue<std::pair<int, int>> bfs;
        bfs.push( {0, 0} );

        std::vector<int> mem(m, INT_MAX);

        while (!bfs.empty()) {
            auto dist = bfs.top().second;
            auto index = bfs.top().first;
            bfs.pop();

            for (int i = starts[target[index] - 'a']; i < n; ++i) {
                if (source[i] == target[index]) {
                    ++index;
                    if (index == m) {
                        return dist + 1;
                    }
                    if (dist >= mem[index]) {
                        continue;
                    }
                    mem[index] = dist;
                    bfs.emplace(index, dist + 1);
                }
            }
        }

        return -1;
    }
};