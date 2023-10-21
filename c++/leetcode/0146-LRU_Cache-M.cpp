// 146 LRU Cache
// https://leetcode.com/problems/lru-cache

// version: 1; create time: 2019-10-21 23:35:04;
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


// 2023/10/31

struct CacheEntry {
    int key;
    int value;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }

    int get(int key) {
        auto iter = key_to_node_.find(key);
        if (iter == key_to_node_.end()) {
            return -1;
        }
        int value = iter->second->value;
        put(key, value);
        return value;
    }

    void put(int key, int value) {
        auto hash_iter = key_to_node_.find(key);
        std::list<CacheEntry>::iterator list_iterator;

        if (hash_iter != key_to_node_.end()) {
            list_iterator = hash_iter->second;
            list_.erase(list_iterator);
        }
        CacheEntry entry{key, value};
        list_iterator = list_.insert(list_.begin(), entry);
        key_to_node_[key] = list_iterator;

        if (list_.size() > capacity_) {
            key_to_node_.erase(list_.back().key);
            list_.pop_back();
        }
    }

private:
    int capacity_;
    std::unordered_map<int, std::list<CacheEntry>::iterator> key_to_node_;
    std::list<CacheEntry> list_;
};

