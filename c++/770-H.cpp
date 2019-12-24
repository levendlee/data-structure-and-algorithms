struct Term {
    int order;
    map<string, int> vars;
    string str;

    Term(string var) : order(1), str(var) {
        vars[var] = 1;
    }

    string calc_str() const {
        string tmp;
        for (const auto& p : vars) {
            for (int i = 0; i < p.second; ++i) {
                if (!tmp.empty()) tmp += "*";
                tmp += p.first;
            }
        }
        return tmp;
    }

    bool operator<(const Term& rhs) const {
        return (order > rhs.order) || ((order == rhs.order) && (str < rhs.str));
    }

    bool operator==(const Term& rhs) const {
        return str == rhs.str;
    }

    Term operator*(const Term& rhs) const {
        Term res = *this;
        res.order += rhs.order;
        for (const auto& p : rhs.vars) {
            res.vars[p.first] += p.second;
        }
        res.str = res.calc_str();
        return res;
    }
};

struct Poly {
    int num;
    std::map<Term, int> terms;

    Poly() {}
    Poly(int num) : num(num) {}
    Poly(const string& var) : num(0) { terms[Term(var)] = 1; }

    Poly operator+(const Poly& rhs) const {
        Poly res = *this;
        res.num += rhs.num;
        for (const auto& p : rhs.terms) {
            res.terms[p.first] += p.second;
        }
        return res;
    }

    Poly operator-(const Poly& rhs) const {
        Poly res = *this;
        res.num -= rhs.num;
        for (const auto& p : rhs.terms) {
            res.terms[p.first] -= p.second;
        }
        return res;
    }

    Poly operator*(const Poly& rhs) const {
        const auto& lhs = *this;

        Poly res;
        res.num = lhs.num * rhs.num;

        for (const auto& p : lhs.terms) {
            res.terms[p.first] += rhs.num * p.second;
        }
        for (const auto& p : rhs.terms) {
            res.terms[p.first] += lhs.num * p.second;
        }

        for (const auto& p0 : lhs.terms) {
            for (const auto& p1 : rhs.terms) {
                auto term = p0.first * p1.first;
                res.terms[term] += p0.second * p1.second;
            }
        }
        return res;
    }

    std::vector<std::string> parts() const {
        std::vector<std::string> res;
        for (const auto& vc : terms) {
            if (vc.second == 0) continue;
            res.push_back(std::to_string(vc.second) + "*" + vc.first.str);
        }
        if (num != 0)
            res.push_back(std::to_string(num));
        return res;
    }
};

class Solution {
private:
    Poly basicOperation(const Poly& lhs, const Poly& rhs, char op) {
        switch (op) {
            case '+': return lhs + rhs;
            case '-': return lhs - rhs;
            case '*': return lhs * rhs;
        }
        return Poly();
    }

    void evaluateTop(std::stack<Poly>& polys, std::stack<char>& ops) {
        const auto rhs = polys.top(); polys.pop();
        const auto lhs = polys.top(); polys.pop();
        const auto res = basicOperation(lhs, rhs, ops.top());
        ops.pop();
        polys.push(res);
    }

    bool isPrecedence(char op0, char op1) {
        return (op0 != '(') &&
               !((op0 == '+' || op0 == '-') && (op1 == '*' || op1 == '/'));
    }

public:
    vector<string> basicCalculatorIV(string expr, vector<string>& evalvars, vector<int>& evalints)
    {
        const int n = expr.size();
        int idx = 0;

        // convert to look up table
        unordered_map<std::string, int> lut;
        const int ne = evalvars.size();
        for (int i = 0; i < ne; ++i) {
            lut[evalvars[i]] = evalints[i];
        }

        // stack of polynomials and operators
        std::stack<Poly> polys;
        std::stack<char> ops;

        while (idx < n) {
            /*
            if (!polys.empty()) {
                std::cout << idx << "," << expr.substr(0, idx - 1) << "\n";
                for (auto& s : polys.top().parts()) {
                    std::cout << s << ", ";
                }
                std::cout << "\n";
            }
            */
            const char c = expr[idx];
            if (isdigit(c)) {
                const int s = idx;
                while (idx < n && isdigit(expr[idx])) ++idx;
                const int num = std::stoi(expr.substr(s, idx - s));
                polys.emplace(num);
                continue;
            }
            if (isalpha(c)) {
                const int s = idx;
                while (idx < n && (isalpha(expr[idx]) || isdigit(expr[idx]))) ++idx;
                const string var = expr.substr(s, idx - s);
                if (lut.count(var)) {
                    polys.emplace(lut[var]);
                } else {
                    polys.emplace(var);
                }
                continue;
            }
            if (c == '(') {
                ops.push('(');
            } else if (c == ')') {
                while (ops.top() != '(') {
                    evaluateTop(polys, ops);
                }
                ops.pop();
            } else if (c != ' ') {
                while (!ops.empty() && isPrecedence(ops.top(), c)) {
                    evaluateTop(polys, ops);
                }
                ops.push(c);
            }
            ++idx;
        }

        while (!ops.empty()) {
            evaluateTop(polys, ops);
        }

        return polys.top().parts();
    }
};