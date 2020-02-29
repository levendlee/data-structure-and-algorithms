// 726 Number of Atoms
// https://leetcode.com/problems/number-of-atoms

// version: 1; create time: 2019-12-14 14:12:26;
class Solution {
public:
    typedef map<string, int> CntMap;

    string readElement(const string& formula, int& pos) {
        const int n = formula.size();
        string res(1, formula[pos]);
        while (++pos < n && isalpha(formula[pos]) && islower(formula[pos])) {
            res += formula[pos];
        }
        return res;
    }

    int readCount(const string& formula, int& pos) {
        const int n = formula.size();
        string tmp = "";
        while (isdigit(formula[pos])) {
            tmp += formula[pos++];
        }
        return tmp.empty() ? 1 : std::stoi(tmp);
    }

    string readSubformula(const string& formula, int& pos) {
        const int n = formula.size();
        const int lpos = pos;
        int level = 0;
        do {
            if (formula[pos] == '(') ++level;
            if (formula[pos] == ')') --level;
            ++pos;
        } while (level != 0);
        return formula.substr(lpos + 1, pos - lpos - 2);
    }

    CntMap analysisFormula(const string& formula) {
        CntMap cnt_map;
        const int n = formula.size();
        int pos = 0;
        while (pos < n) {
            if (isalpha(formula[pos])) {
                auto elem = readElement(formula, pos);
                auto cnt = readCount(formula, pos);
                cnt_map[elem] += cnt;
            } else {
                auto subf = readSubformula(formula, pos);
                auto sub_cnt_map = analysisFormula(subf);
                auto cnt = readCount(formula, pos);
                for (const auto& p : sub_cnt_map) {
                    cnt_map[p.first] += p.second * cnt;
                }
            }
        }

        return cnt_map;
    }

    string countOfAtoms(string formula) {
        auto cnt_map = analysisFormula(formula);
        string res = "";
        for (const auto& p : cnt_map) {
            res += p.first;
            if (p.second != 1) {
                res += std::to_string(p.second);
            }
        }
        return res;
    }
};
