class Logger {
private:
    using HT = std::unordered_set<std::string>;
    using QT = std::queue<std::pair<int, typename HT::iterator>>;

    HT msg_hash_;
    QT msg_queue_;

public:
    /** Initialize your data structure here. */
    Logger() {

    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        while (!msg_queue_.empty()) {
            auto previous = msg_queue_.front().first;
            auto iterator = msg_queue_.front().second;
            if (timestamp - previous >= 10) {
                msg_queue_.pop();
                msg_hash_.erase(iterator);
            } else {
                break;
            }
        }
        bool should = !msg_hash_.count(message);
        if (should) {
            auto iterator = msg_hash_.insert(message).first;
            msg_queue_.emplace(timestamp, iterator);
        }
        return should;
    }
};