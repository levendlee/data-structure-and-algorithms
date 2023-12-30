// 815 Bus Routes
// https://leetcode.com/problems/bus-routes

// version: 1; create time: 2019-12-14 15:27:59;
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        const int n = routes.size();
        if (S == T) return 0;

        unordered_map<int, vector<int>> stations;
        for (int r = 0; r < n; ++r) {
            for (const auto& s : routes[r]) {
                stations[s].push_back(r);
            }
        }

        unordered_set<int> visited_s;
        unordered_set<int> visited_r;

        int stops = 1;
        queue<int> bfs;
        visited_s.insert(S);
        for (const auto& r : stations[S]) {
            bfs.push(r);
            visited_r.insert(r);
        }

        // Reduce to route to router might be faster
        while (!bfs.empty()) {
            const int nn = bfs.size();
            for (int i = 0; i < nn; ++i) {
                auto r = bfs.front();
                bfs.pop();
                for (const auto& s : routes[r]) {
                    if (s == T) {
                        return stops;
                    }
                    if (visited_s.count(s)) {
                        continue;
                    }
                    visited_s.insert(s);
                    for (const auto& nr : stations[s]) {
                        if (visited_r.count(nr)) {
                            continue;
                        }
                        visited_r.insert(nr);
                        bfs.push(nr);
                    }
                }
            }
            ++stops;
        }

        return -1;
    }
};

//

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, vector<int>> station2routes;
        for (int i = 0; i < routes.size(); ++i) {
            for (int station: routes[i]) {
                station2routes[station].push_back(i);
            }
        }

        unordered_set<int> visited_station;
        visited_station.insert(source);
        unordered_set<int> visited_route;
    
        queue<int> bfs;
        bfs.push(source);

        int stops = 0;
        while (!bfs.empty()) {
            ++stops;
            int search_size = bfs.size();
            for (int i = 0; i < search_size; ++i) {
                int station = bfs.front();
                bfs.pop();

                for (int r: station2routes[station]) {
                    if (visited_route.count(r)) continue;
                    visited_route.insert(r);
                    for (int s: routes[r]) {
                        if (s == target) return stops;
                        if (visited_station.count(s)) continue;
                        visited_station.insert(s);
                        bfs.push(s);
                    }
                }
            }
        }

        return -1;
    }
};
