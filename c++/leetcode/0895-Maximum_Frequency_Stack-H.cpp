// 895 Maximum Frequency Stack
// https://leetcode.com/problems/maximum-frequency-stack

// version: 1; create time: 2020-01-25 16:15:23;
class FreqStack {
private:
    int max_freq_;
    unordered_map<int, vector<int>> freq_to_num_;
    unordered_map<int, int> num_to_freq_;

public:
    FreqStack() : max_freq_(0) {

    }

    void push(int x) {
        const auto freq = ++num_to_freq_[x];
        freq_to_num_[freq].push_back(x);
        max_freq_ = std::max(max_freq_, freq);
    }

    int pop() {
        auto& num_list = freq_to_num_[max_freq_];
        const auto x = num_list.back(); num_list.pop_back();
        --num_to_freq_[x];
        if (num_list.empty()) {
            freq_to_num_.erase(max_freq_--);
        }
        if (num_to_freq_[x] == 0) {
            num_to_freq_.erase(x);
        }
        return x;
    }
};
