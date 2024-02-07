// 1249 Minimum Remove to Make Valid Parentheses
// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses

// version: 1; create time: 2020-01-15 18:45:14;
class Solution
{
public:
    void removeHelper(string &s, const int start, const char l_op, const char r_op)
    {
        int stack = 0;
        int idx = start;
        const int n = s.size();
        while (idx < n)
        {
            if (s[idx] == l_op)
                ++stack;
            else if (s[idx] == r_op)
                --stack;
            if (stack < 0)
                break;
            ++idx;
        }
        if (idx == n)
        {
            std::reverse(s.begin(), s.end());
            if (l_op == ')')
            {
                return;
            }
            else
            {
                removeHelper(s, 0, ')', '(');
            }
        }
        else
        {
            s.erase(idx, 1);
            removeHelper(s, idx, l_op, r_op);
        }
    }

    string minRemoveToMakeValid(string s)
    {
        removeHelper(s, 0, '(', ')');
        return s;
    }
};

//

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        unordered_set<int> remove_idx;
        stack<int> stk;

        const int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            char c = s[i];

            if (c == '(')
            {
                stk.push(i);
            }
            else if (c == ')')
            {
                if (stk.empty())
                {
                    remove_idx.insert(i);
                }
                else
                {
                    stk.pop();
                }
            }
        }
        while (!stk.empty())
        {
            remove_idx.insert(stk.top());
            stk.pop();
        }

        string removed_s;
        int i = 0, j = 0;
        while (i < n)
        {
            if (remove_idx.count(i))
            {
                ++i;
            }
            else
            {
                removed_s.push_back(s[i]);
                ++i;
            }
        }

        return removed_s;
    }
};

//

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        function<string(const string &, char, char)> remove_invalid;
        remove_invalid = [&](const string &s, char lc, char rc)
        {
            int stk = 0;
            string res;
            for (char c : s)
            {
                if (c == lc)
                {
                    ++stk;
                    res += c;
                }
                else if (c == rc)
                {
                    --stk;
                    if (stk < 0)
                    {
                        stk = 0;
                    }
                    else
                    {
                        res += c;
                    }
                }
                else
                {
                    res += c;
                }
            }
            return res;
        };

        auto temp = remove_invalid(s, '(', ')');
        reverse(temp.begin(), temp.end());
        temp = remove_invalid(temp, ')', '(');
        reverse(temp.begin(), temp.end());
        return temp;
    }
};