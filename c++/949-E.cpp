class Solution {
private:
    bool exist_;
    int max_hour_;
    int max_min_;


public:
    void check(vector<int>& A, int idx, int hour, int min) {
        if (idx >= 4) {
            if (hour > max_hour_ || (hour == max_hour_) && (min >= max_min_)) {
                exist_ = true;
                max_hour_ = hour;
                max_min_ = min;
            }
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int nh = hour, nm = min;
            if (A[i] >= 0) {
                constexpr int h_mult[] = {10, 1, 0, 0};
                constexpr int m_mult[] = {0, 0, 10, 1};
                nh = hour + A[i] * h_mult[idx];
                nm = min + A[i] * m_mult[idx];
                if (nh > 23 || nm > 59) {
                    continue;
                }
                A[i] = -A[i] - 1;
                check(A, idx + 1, nh, nm);
                A[i] = -A[i] - 1;
            }
        }
    }

    string getTwoDigits(int num) {
        return num >= 10 ? std::to_string(num) : "0" + std::to_string(num);
    }

    string largestTimeFromDigits(vector<int>& A) {
        exist_ = false;
        max_hour_ = 0;
        max_min_ = 0;
        check(A, 0, 0, 0);
        return exist_ ? (getTwoDigits(max_hour_) + ":" + getTwoDigits(max_min_)) : "";
    }
};