// 788 Rotated Digits
// https://leetcode.com/problems/rotated-digits

// version: 1; create time: 2020-02-08 16:34:28;
constexpr char changed[4] = {'2','6','9','5'};
constexpr char unchanged[3] = {'0','1','8'};

class Solution {
public:
    int rotated(const string& s, const string& N) {
        if (s.size() > N.size() || (s.size() == N.size() && s > N)) return 0;
        int cnt = !s.empty() && (s[0] != '0');
        for (int i = 0; i < 4; ++i) cnt += rotated(s + changed[i], N);
        for (int i = 0; i < 3; ++i) cnt += rotated(s + unchanged[i], N);
        return cnt;
    }

    int rotated_eq(const string& s, const string& N) {
        if (s.size() > N.size() || (s.size() == N.size() && s > N)) return 0;
        int cnt = !s.empty() && (s[0] != '0');
        for (int i = 0; i < 3; ++i) cnt += rotated_eq(s + unchanged[i], N);
        return cnt;
    }

    int rotatedDigits(int N_) {
        string N = std::to_string(N_);
        return rotated("", N) - rotated_eq("", N);
    }
};
