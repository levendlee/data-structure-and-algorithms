enum class Win{
    MustWin = 0,
    MustLoss = 1,
    WinOrLoss = 2,
    Unknown = 3
};

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<Win> win(n, Win::Unknown);
        return winnerSquareGameHelper(n, win) == Win::MustWin;
    }
    
    Win winnerSquareGameHelper(int n, vector<Win>& win) {
        if (n == 0) {
            return Win::MustLoss;
        }
        if (win[n - 1] != Win::Unknown) {
            return win[n - 1];
        }
        const int max_step = int(sqrt(n));
        if (max_step * max_step == n) {
            win[n - 1] = Win::MustWin;
        } else {
            int win_cnt = 0, loss_cnt = 0, total_cnt = max_step;
            for (int i = 1; i <= max_step; ++i) {
                Win res = winnerSquareGameHelper(n - i * i, win);
                if (res == Win::MustWin) {
                    win_cnt++;
                } else if (res == Win::MustLoss) {
                    loss_cnt++;
                    break;
                }
            }
            if (win_cnt == total_cnt) {
                win[n - 1] = Win::MustLoss;
            } else if (loss_cnt != 0) {
                win[n - 1] = Win::MustWin;
            } else {
                win[n - 1] = Win::WinOrLoss;
            }
        }
        return win[n - 1];
    }
};