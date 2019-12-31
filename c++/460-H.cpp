class LFUCache {
private:
    int capacity_;
    multimap<int, pair<int, int>> freq_to_key_val_;
    unordered_map<int, multimap<int, pair<int, int>>::iterator> key_to_iter_;

public:
    LFUCache(int capacity) : capacity_(capacity) {

    }

    void update(int key) {
        auto& prev = key_to_iter_[key];
        auto update = freq_to_key_val_.insert(std::make_pair(prev->first + 1, prev->second));
        freq_to_key_val_.erase(prev);
        key_to_iter_[key] = update;
    }

    int get(int key) {
        if (key_to_iter_.count(key)) {
            update(key);
            return key_to_iter_[key]->second.second;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (capacity_ == 0) return;

        if (key_to_iter_.count(key)) {
            update(key);
            key_to_iter_[key]->second.second = value;
        } else {
            if (key_to_iter_.size() == capacity_) {
                auto iter0 = freq_to_key_val_.begin();
                auto iter1 = key_to_iter_[iter0->second.first];
                key_to_iter_.erase(iter0->second.first);
                freq_to_key_val_.erase(iter0);
            }
            auto iter = freq_to_key_val_.insert(std::make_pair(1, std::make_pair(key, value)));
            key_to_iter_[key] = iter;
        }
    }
};