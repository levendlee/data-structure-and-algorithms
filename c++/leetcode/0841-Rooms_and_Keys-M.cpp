class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int n = rooms.size();

        vector<bool> visited(n, false);
        function<void(int)> dfs;
        dfs = [&](int i) {
            if (visited[i]) return;
            visited[i] = true;
            for (int j : rooms[i]) {
                dfs(j);
            }
        };
        dfs(0);

        return accumulate(visited.begin(), visited.end(), 0) == n;
    }
};
