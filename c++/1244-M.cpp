class Leaderboard {
private:
    unordered_map<int, int> hashmap_;
    set<pair<int, int>> treemap_;

    void resetTreemap(int playerId) {
        if (hashmap_.count(playerId)) {
            const auto old_score = hashmap_[playerId];
            const auto old_record = std::make_pair(-old_score, playerId);
            treemap_.erase(old_record);
        }
    }

public:
    Leaderboard() {

    }

    void addScore(int playerId, int score) {
        resetTreemap(playerId);
        const auto new_score = hashmap_[playerId] += score;
        const auto new_record = std::make_pair(-new_score, playerId);
        treemap_.insert(new_record);
    }

    int top(int K) {
        int sum = 0;
        auto iter = treemap_.begin();
        while (--K >= 0) {
            sum += -iter->first;
            ++iter;
        }
        return sum;
    }

    void reset(int playerId) {
        resetTreemap(playerId);
        hashmap_[playerId] = 0;
    }
};