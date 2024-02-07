class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> order;
        vector<vector<int>> prereq(numCourses);
        for (const auto &pr : prerequisites)
        {
            prereq[pr[0]].push_back(pr[1]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> cur_visited(numCourses, false);
        std::function<bool(int)> topology_sort;
        topology_sort = [&](int i)
        {
            if (visited[i])
            {
                return true;
            }
            if (cur_visited[i])
            {
                return false;
            }
            cur_visited[i] = true;

            for (const int nex : prereq[i])
            {
                if (!topology_sort(nex))
                {
                    cur_visited[i] = false;
                    return false;
                }
            }

            order.push_back(i);

            cur_visited[i] = false;
            visited[i] = true;

            return true;
        };

        for (int i = 0; i < numCourses; ++i)
        {
            if (visited[i])
                continue;
            if (!topology_sort(i))
            {
                return {};
            }
        }

        return order;
    }
};

//

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        std::vector<bool> visited(numCourses, false);
        std::vector<bool> onpath(numCourses, false);

        std::unordered_map<int, vector<int>> prerequisite_map;
        for (const auto &vec : prerequisites)
        {
            prerequisite_map[vec[0]].push_back(vec[1]);
        }

        function<bool(int)> detect_cycle;
        detect_cycle = [&](int course)
        {
            if (onpath[course])
                return true;
            if (visited[course])
                return false;
            onpath[course] = true;

            for (const auto &pre : prerequisite_map[course])
            {
                if (detect_cycle(pre))
                {
                    onpath[course] = false;
                    return true;
                }
            }
            onpath[course] = false;
            visited[course] = true;
            return false;
        };

        for (int i = 0; i < numCourses; ++i)
        {
            if (detect_cycle(i))
            {
                return false;
            }
        }

        return true;
    }
};