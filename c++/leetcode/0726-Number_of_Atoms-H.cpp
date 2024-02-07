// 726 Number of Atoms
// https://leetcode.com/problems/number-of-atoms

// version: 1; create time: 2019-12-14 14:12:26;
class Solution
{
public:
    typedef map<string, int> CntMap;

    string readElement(const string &formula, int &pos)
    {
        const int n = formula.size();
        string res(1, formula[pos]);
        while (++pos < n && isalpha(formula[pos]) && islower(formula[pos]))
        {
            res += formula[pos];
        }
        return res;
    }

    int readCount(const string &formula, int &pos)
    {
        const int n = formula.size();
        string tmp = "";
        while (isdigit(formula[pos]))
        {
            tmp += formula[pos++];
        }
        return tmp.empty() ? 1 : std::stoi(tmp);
    }

    string readSubformula(const string &formula, int &pos)
    {
        const int n = formula.size();
        const int lpos = pos;
        int level = 0;
        do
        {
            if (formula[pos] == '(')
                ++level;
            if (formula[pos] == ')')
                --level;
            ++pos;
        } while (level != 0);
        return formula.substr(lpos + 1, pos - lpos - 2);
    }

    CntMap analysisFormula(const string &formula)
    {
        CntMap cnt_map;
        const int n = formula.size();
        int pos = 0;
        while (pos < n)
        {
            if (isalpha(formula[pos]))
            {
                auto elem = readElement(formula, pos);
                auto cnt = readCount(formula, pos);
                cnt_map[elem] += cnt;
            }
            else
            {
                auto subf = readSubformula(formula, pos);
                auto sub_cnt_map = analysisFormula(subf);
                auto cnt = readCount(formula, pos);
                for (const auto &p : sub_cnt_map)
                {
                    cnt_map[p.first] += p.second * cnt;
                }
            }
        }

        return cnt_map;
    }

    string countOfAtoms(string formula)
    {
        auto cnt_map = analysisFormula(formula);
        string res = "";
        for (const auto &p : cnt_map)
        {
            res += p.first;
            if (p.second != 1)
            {
                res += std::to_string(p.second);
            }
        }
        return res;
    }
};

//

class Solution
{
public:
    string countOfAtoms(string formula)
    {
        stack<map<string, int>> stk;
        stk.push({});

        int n = formula.size();
        int i = 0;
        while (i < n)
        {
            if (isalpha(formula[i]))
            {
                int j = i + 1;
                while (j < n && isalpha(formula[j]) && islower(formula[j]))
                    ++j;
                string name = formula.substr(i, j - i);
                i = j;

                while (j < n && isdigit(formula[j]))
                    ++j;
                int count = i == j ? 1 : stoi(formula.substr(i, j - i));
                i = j;

                stk.top()[name] += count;
            }
            else if (formula[i] == '(')
            {
                stk.push({});
                ++i;
            }
            else if (formula[i] == ')')
            {
                int j = ++i;
                while (j < n && isdigit(formula[j]))
                    ++j;
                int times = i == j ? 1 : stoi(formula.substr(i, j - i));
                i = j;

                auto count_map = stk.top();
                stk.pop();
                for (const auto &[name, cnt] : count_map)
                {
                    stk.top()[name] += cnt * times;
                }
            }
        }

        string res;
        for (const auto &[name, cnt] : stk.top())
        {
            res += name + (cnt == 1 ? "" : to_string(cnt));
        }
        return res;
    }
};

//

class Solution
{
public:
    string countOfAtoms(string formula)
    {
        stack<map<string, int>> stk;
        stk.push({});

        const int n = formula.size();
        int i = 0;
        while (i < n)
        {
            const char c = formula[i];
            if (c == '(')
            {
                stk.push({});
                ++i;
            }
            else if (c == ')')
            {
                auto cnt_map = move(stk.top());
                stk.pop();
                ++i;
                int j = i;
                while (j < n && isdigit(formula[j]))
                    ++j;
                int mul = 1;
                if (j > i)
                {
                    mul = stoi(formula.substr(i, j - i));
                }
                for (const auto [atom, cnt] : cnt_map)
                {
                    stk.top()[atom] += cnt * mul;
                }
                i = j;
            }
            else
            {
                int j = i + 1;
                while (j < n && islower(formula[j]))
                    ++j;
                string atom = formula.substr(i, j - i);
                int cnt = 1;
                i = j;
                j = i;
                while (j < n && isdigit(formula[j]))
                    ++j;
                if (j > i)
                {
                    cnt = stoi(formula.substr(i, j - 1));
                }
                stk.top()[atom] += cnt;
                i = j;
            }
        }

        string res;
        for (const auto &[atom, cnt] : stk.top())
        {
            res += atom;
            if (cnt > 1)
            {
                res += to_string(cnt);
            }
        }
        return res;
    }
};