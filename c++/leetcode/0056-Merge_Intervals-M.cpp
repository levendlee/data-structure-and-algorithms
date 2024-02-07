// 56 Merge Intervals
// https://leetcode.com/problems/merge-intervals

// version: 1; create time: 2019-12-14 15:34:25;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        if (intervals.empty())
            return res;

        std::sort(intervals.begin(), intervals.end());
        for (const auto &it : intervals)
        {
            if (res.empty() || res.back()[1] < it[0])
            {
                res.push_back(it);
            }
            else
            {
                res.back()[1] = std::max(res.back()[1], it[1]);
            }
        }

        return res;
    }
};

// 2023/10/09

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> res;
        if (intervals.empty())
        {
            return res;
        }
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i)
        {
            const auto &interval = intervals[i];
            if (end < interval[0])
            {
                res.push_back({start, end});
                start = interval[0];
                end = interval[1];
            }
            else
            {
                end = std::max(end, interval[1]);
            }
        }
        res.push_back({start, end});
        return res;
    }
};

//

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        int start_time = INT_MIN;
        int end_time = INT_MIN;
        for (const auto &interval : intervals)
        {
            if (end_time < interval[0])
            {
                if (start_time >= 0)
                {
                    res.push_back({start_time, end_time});
                }
                start_time = interval[0];
                end_time = interval[1];
            }
            else
            {
                end_time = max(end_time, interval[1]);
            }
        }
        res.push_back({start_time, end_time});
        return res;
    }
};