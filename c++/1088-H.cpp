class Solution {
private:
    int cnt_;
    unordered_map<int, bool> mem_;

public:
    // Using strobogrammatic number will be much faster
    bool isConfusing(const string& s) {
        if (s.empty()) return true;

        const int n = s.size();

        int l = 0, r = n - 1;
        while (l < n && s[l] == '0') l++;

        bool confusing = true;
        while (l < r) {
            if (s[l] == '6') {
                if (s[r] != '9') {
                    confusing = false;
                    break;
                }
            } else if (s[l] == '9') {
                if (s[r] != '6') {
                    confusing = false;
                    break;
                }
            } else if (s[l] != s[r]) {
                confusing = false;
                break;
            }
            ++l;
            --r;
        }
        if (l == r)
        {
            if (s[l] == '6' || s[l] == '9') {
                confusing = false;
            }
        }

        return confusing;
    }

    void dfs(string& s, const string& limit) {
        if ((s.size() == limit.size()) && (s > limit)) {
            return;
        }

        cnt_ += !isConfusing(s);

        if (s.size() == limit.size()) {
            return;
        }

        constexpr char digits[] = {'0', '1', '8', '6', '9'};
        for (int i = 0; i < 5; ++i) {
            if ((i == 0) && (s.empty())) continue;

            s.push_back(digits[i]);
            dfs(s, limit);
            s.pop_back();
        }

    }

    void dfs(string& s, const string& limit) {
        if (s.empty()) {
            constexpr char digits[] = {'0', '1', '8'};
            for (int i = 0; i < 3; ++i) {
                s.push_back(digits[i]);
                dfs(s, limit);
                s.pop_back();
            }
        } else {
            if ((s.size() == limit.size()) && (s.size() > limit.size())) return;

            constexpr char pairs[][2] = {{'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
            for (int i = 0; i < 4; ++i) {
                s.insert(s.begin(), pairs[i][0]);
                s.push_back(pairs[i][1]);

                dfs(s, limit);

                s.erase(s.begin());
                s.pop_back();
            }
        }
    }
    int confusingNumberII(int N) {
        string s = "";
        dfs(s, std::to_string(N));
        return cnt_;
    }
};