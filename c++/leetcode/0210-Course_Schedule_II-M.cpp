class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        vector<vector<int>> prereq(numCourses);
        for (const auto& pr : prerequisites) {
            prereq[pr[0]].push_back(pr[1]);
        }
        
        vector<bool> visited(numCourses, false);
        vector<bool> cur_visited(numCourses, false);
        std::function<bool(int)> topology_sort;
        topology_sort = [&](int i) {
            if (visited[i]) {
                return true;
            }
            if (cur_visited[i]) {
                return false;
            }
            cur_visited[i] = true;

            for (const int nex : prereq[i]) {
                if (!topology_sort(nex)) {
                    cur_visited[i] = false;
                    return false;
                }
            }

            order.push_back(i);

            cur_visited[i] = false;
            visited[i] = true;

            return true;
        };

        for (int i = 0; i < numCourses; ++i) {
            if (visited[i]) continue;
            if (!topology_sort(i)) {
                return {};
            }
        }

        return order;
    }
};
