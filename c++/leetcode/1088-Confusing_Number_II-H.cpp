// 1088 Confusing Number II
// https://leetcode.com/problems/confusing-number-ii

// version: 2; create time: 2020-02-17 22:12:14;
class Solution {
public:
    bool isSmaller(const string& num, const string& limit) {
        return num.size() > limit.size() || num.size() == limit.size() && num > limit;
    }

    int rotateSame(const string& num, const string& limit) {
        if (isSmaller(num, limit)) return 0;
        int cnt = !num.empty() && (num[0] != '0');
        constexpr char starts[] = "01689";
        constexpr char ends[] = "01986";
        for (int k = 0; k < 5; ++k) {
            cnt += rotateSame(starts[k] + num + ends[k], limit);
        }
        return cnt;
    }

    int rotateLegal(const string& num, const string& limit) {
        if (isSmaller(num, limit)) return 0;
        int cnt = !num.empty() && (num[0] != '0');
        constexpr char digits[] = "01689";
        for (int k = 0; k < 5; ++k) {
            cnt += rotateLegal(num + digits[k], limit);
        }
        return cnt;
    }

    int confusingNumberII(int N) {
        string n_str = to_string(N);
        int total = rotateLegal("", n_str);
        int same = rotateSame("", n_str);
        constexpr char samec[] = "018";
        for (int k = 0; k < 3; ++k) {
            same += rotateSame(string(1, samec[k]), n_str);
        }
        return total - same;
    }
};


// version: 1; create time: 2019-10-26 20:11:52;
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
