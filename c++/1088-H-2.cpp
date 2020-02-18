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