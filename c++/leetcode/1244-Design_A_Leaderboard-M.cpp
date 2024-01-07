// 1244 Design A Leaderboard
// https://leetcode.com/problems/design-a-leaderboard

// version: 1; create time: 2020-01-25 22:11:16;
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

//

class Leaderboard {
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        auto iter = hashmap_.find(playerId);
        if (iter != hashmap_.end()) {
            tree_.erase({hashmap_[playerId], playerId});
        }
        hashmap_[playerId] += score;
        tree_.insert({hashmap_[playerId], playerId});
    }
    
    int top(int K) {
        int sum = 0;
        auto iter = tree_.rbegin();
        for (int k = 0; k < K; ++k, ++iter) {
            sum += iter->first;
        }
        return sum;
    }
    
    void reset(int playerId) {
        tree_.erase({hashmap_[playerId], playerId});
        hashmap_.erase(playerId);
    }

private:
    unordered_map<int, int> hashmap_;
    set<pair<int, int>> tree_;
};