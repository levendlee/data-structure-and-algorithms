class Solution
{
public:
    bool isSolvable(vector<string> &words, string result)
    {
        int coeffs[26] = {0};
        bool leading[26] = {false};
        for (const auto &s : words)
        {
            const int n = s.size();
            int base = 1;
            for (int i = n - 1; i >= 0; --i)
            {
                coeffs[s[i] - 'A'] += base;
                base *= 10;
            }
            if (s.size() > 1)
            {
                leading[s[0] - 'A'] = true;
            }
        }
        {
            const int n = result.size();
            int base = 1;
            for (int i = n - 1; i >= 0; --i)
            {
                coeffs[result[i] - 'A'] -= base;
                base *= 10;
            }
            if (result.size() > 1)
            {
                leading[result[0] - 'A'] = true;
            }
        }

        function<bool(int, int, int)> backtracking;
        backtracking = [&](int index, int mask, int target)
        {
            for (int i = index; i <= 26; ++i)
            {
                if (i == 26 || coeffs[i] != 0)
                {
                    index = i;
                    break;
                }
            }
            if (index == 26)
            {
                return target == 0;
            }
            for (int i = 0; i <= 9; ++i)
            {
                if (i == 0 && leading[index])
                    continue;
                if (!(mask & (1 << i)))
                {
                    if (backtracking(index + 1, mask | (1 << i), target + i * coeffs[index]))
                    {
                        return true;
                    }
                }
            }
            return false;
        };

        return backtracking(0, 0, 0);
    }
};

//

class Solution
{
public:
    bool isSolvable(vector<string> &words, string result)
    {
        words.push_back(result);
        const int n = words.size();

        int coeffs[26];
        fill(coeffs, coeffs + 26, 0);

        for (int i = 0; i < n; ++i)
        {
            int base = 1;
            for (int j = words[i].size() - 1; j >= 0; --j)
            {
                char c = words[i][j];
                coeffs[c - 'A'] += i == n - 1 ? base : -base;
                base *= 10;
            }
        }

        bool leadings[26];
        fill(leadings, leadings + 26, false);

        for (int i = 0; i < n; ++i)
        {
            if (words[i].size() == 1)
                continue;
            leadings[words[i][0] - 'A'] = true;
        }

        function<bool(int, int, int)> backtracking;
        backtracking = [&](int c_index, int num_mask, int total)
        {
            while (c_index < 26 && coeffs[c_index] == 0)
                ++c_index;
            if (c_index == 26)
            {
                return total == 0;
            }
            for (int num = 0; num <= 9; ++num)
            {
                if (num_mask & (1 << num))
                    continue;
                if (num == 0 && leadings[c_index])
                    continue;
                if (backtracking(c_index + 1, num_mask | (1 << num), total + coeffs[c_index] * num))
                {
                    return true;
                }
            }
            return false;
        };
        return backtracking(0, 0, 0);
    }
};