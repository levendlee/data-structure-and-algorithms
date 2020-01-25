class Solution {
private:
    string next_close_time_;

public:
    void findNext(const string& pre_time, string& next_time, vector<char>& digits) {
        if (next_time.size() == 5) {
            if ((next_time.substr(0, 2) < "24") && (next_time.substr(3, 2) < "60") && (pre_time < next_time))  {
                if (next_close_time_.empty() || next_close_time_ > next_time) {
                    next_close_time_ = next_time;
                }
            }
            return;
        }
        if (next_time.size() == 2) {
            next_time.push_back(':');
            findNext(pre_time, next_time, digits);
            next_time.pop_back();
            return;
        }
        for (const auto& c : digits) {
            next_time.push_back(c);
            findNext(pre_time, next_time, digits);
            next_time.pop_back();
        }
    }

    string nextClosestTime(string time) {
        vector<char> digits;
        for (const char& c : time) {
            if (c != ':') digits.push_back(c);
        }
        std::sort(digits.begin(), digits.end());

        const auto it = std::unique(digits.begin(), digits.end());
        digits.resize(std::distance(digits.begin(), it));

        next_close_time_ = "";
        string next_time;
        findNext(time, next_time, digits);
        if (next_close_time_.empty()) next_close_time_ = string(2, digits[0]) + ":" + string(2, digits[0]);
        return next_close_time_;
    }
};