class Solution {
private:
    int n_;
    int k_;
    std::string ans_;
    std::vector<bool> visit_;

public:
    /*
    // DFS Implementation
    void dfs(std::string prefix) {
        for (int i = 0; i < k_; ++i) {
            auto c = char(i + '0');
            auto str = prefix + c;
            auto num = std::stoi(str);
            if (!visit_[num]) {
                visit_[num] = true;
                dfs(str.substr(1, n_ - 1));
                ans_.push_back(c);
            }
        }
    }

    string crackSafe(int n, int k) {
        n_ = n;
        k_ = k;
        visit_ = std::vector<bool>(pow(10, n), false);
        dfs(std::string(n - 1, '0'));
        ans_ += std::string(n - 1, '0');
        //std::reverse(ans_.begin(), ans_.end());
        return ans_;
    }
    */

    // Non-DFS Implementation
    string crackSafe(int n, int k) {
        std::vector<int8_t> edges(pow(10, n), 0);

        std::stack<int> path;
        std::string circuit;
        int cur_v = 0;

        int base = pow(10, n - 1);
        do {
            if (edges[cur_v % base] < k) {
                path.push(cur_v);
                cur_v = (cur_v % base) * 10 + edges[cur_v % base]++;
            } else {
                circuit.push_back((cur_v % 10) + '0');
                cur_v = path.top(); path.pop();
            }
        } while (!path.empty());
        circuit += std::string(n - 1, '0');
        return circuit;
    }
};