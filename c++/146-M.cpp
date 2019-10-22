class LRUCache {
private:
    int capacity_;
    std::list<int> hist_;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache_;

    void updateHistory(int key) {
        auto iter = cache_[key].second;
        hist_.erase(iter);
        cache_[key].second = hist_.insert(hist_.end(), key);
    }

public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }


    int get(int key) {
        if (cache_.count(key)) {
            updateHistory(key);
            return cache_[key].first;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (cache_.count(key)) {
            updateHistory(key);
            cache_[key].first = value;
        } else {
            if (cache_.size() == capacity_) {
                auto remove_key = hist_.front();
                hist_.pop_front();
                cache_.erase(remove_key);
            }
            auto iter = hist_.insert(hist_.end(), key);
            cache_[key] = std::make_pair(value, iter);
        }
    }
};