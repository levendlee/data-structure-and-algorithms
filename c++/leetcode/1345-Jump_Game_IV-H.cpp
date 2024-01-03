class Solution {
public:
    int minJumps(vector<int>& arr) {
        if (arr.size() == 1) return 0;

        const int n = arr.size();
        unordered_map<int, vector<int>> value2index;
        for (int i = n - 1; i >= 0; --i) {
            if (i - 1 >= 0 && i + 1 < n && arr[i - 1] == arr[i] && arr[i] == arr[i + 1]) continue;
            value2index[arr[i]].push_back(i);
        }

        vector<bool> visited(n, false);
        visited[0] = true;
        queue<int> bfs;
        bfs.push(0);

        auto push_index = [&](int index) {
            if (index == n - 1) return true;
            if (index >= 0 && index < n && !visited[index]) {
                visited[index] = true;
                bfs.push(index);
            }
            return false;
        };
    
        int steps = 0;
        while (!bfs.empty()) {
            ++steps;
            int search_space = bfs.size();
            for (int i = 0; i < search_space; ++i) {
                int index = bfs.front();
                bfs.pop();
                if (push_index(index + 1)) return steps;
                if (push_index(index - 1)) return steps;
                for (int next : value2index[arr[index]]) {
                    if (next == index) continue;
                    if (push_index(next)) return steps;
                }
                value2index[arr[index]].clear();
            }
        }

        return -1;
    }
};
