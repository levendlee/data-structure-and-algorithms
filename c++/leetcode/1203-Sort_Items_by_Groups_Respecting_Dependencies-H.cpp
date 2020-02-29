// 1203 Sort Items by Groups Respecting Dependencies
// https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies

// version: 1; create time: 2019-12-17 21:38:31;
class Solution {
public:
    bool tpSort1(vector<vector<int>>& sorted_items,
                vector<int>& group,
                vector<vector<int>>& before_items,
                vector<bool>& visited,
                vector<bool>& onpath,
                int item) {
        if (visited[item]) return true;
        if (onpath[item]) return false;

        onpath[item] = true;
        int group_id = group[item];
        for (const auto& prev_item : before_items[item]) {
            if (!tpSort1(sorted_items, group, before_items, visited, onpath, prev_item)) {
                return false;
            }
        }
        onpath[item] = false;
        visited[item] = true;

        sorted_items[group_id].push_back(item);
        return true;
    }

    bool tpSort2(vector<int>& sorted_groups,
                 vector<vector<int>>& before_groups,
                 vector<bool>& visited,
                 vector<bool>& onpath,
                 int group) {
        if (visited[group]) return true;
        if (onpath[group]) return false;

        onpath[group] = true;
        for (const auto& prev_group : before_groups[group]) {
            if (!tpSort2(sorted_groups, before_groups, visited, onpath, prev_group)) {
                return false;
            }
        }
        onpath[group] = false;
        visited[group] = true;

        sorted_groups.push_back(group);
        return true;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& before_items) {
        // Assign all items with a group
        for(auto& id : group) {
            if (id == -1) {
                id = m++;
            }
        }

        // Figure out the ordering of the groups
        vector<vector<int>> before_groups(m);
        for (int i = 0; i < n; ++i) {
            for (const auto& j : before_items[i]) {
                if (group[i] != group[j])
                    before_groups[group[i]].push_back(group[j]);
            }
        }

        // Sort the items inside the groups
        vector<vector<int>> sorted_items(m);
        vector<bool> visited_items(n, false), onpath_items(n, false);
        for (int i = 0; i < n; ++i) {
            if (!tpSort1(sorted_items, group, before_items, visited_items, onpath_items, i)) {
                return {};
            }
        }

        // Sort the groups
        vector<int> sorted_groups;
        vector<bool> visited_groups(m, false), onpath_groups(m, false);
        for (int i = 0; i < m; ++i) {
            if (!tpSort2(sorted_groups, before_groups, visited_groups, onpath_groups, i)) {
                return {};
            }
        }

        // Output sorted items
        vector<int> res;
        for (auto& group : sorted_groups) {
            for (auto& item : sorted_items[group]) {
                res.push_back(item);
            }
        }
        return res;
    }
};

