class AllOne {
private:
    // sorted value list. in decreasing order.
    list<int> vals_;
    // hashmap from key to its value and the iterator of key list
    unordered_map<string, pair<int, list<string>::iterator>> key_to_val_;
    // hashmap from value to its key list and the iterator of the value list
    unordered_map<int, pair<list<string>, list<int>::iterator>> val_to_key_;

    void inc_or_dec(string key, int dif) {
        int new_val;
        list<int>::iterator new_val_iter;

        if (key_to_val_.count(key)) {
            const auto old_val = key_to_val_[key].first;
            const auto old_iter = key_to_val_[key].second;

            // update the value list. find or insert the new value in the value list
            new_val = old_val + dif;
            const auto val_iter = val_to_key_[old_val].second;
            const auto prev_iter = std::prev(val_iter);
            const auto next_iter = std::next(val_iter);
            new_val_iter = dif > 0 ? ((val_iter != vals_.begin() && *prev_iter == new_val) ? prev_iter :
                                        vals_.insert(val_iter, new_val)) :
                                     ((next_iter != vals_.end() && *next_iter == new_val) ? next_iter:
                                        vals_.insert(next_iter, new_val));

            // update the key list. clean up old val to key list reference
            val_to_key_[old_val].first.erase(old_iter);
            if (val_to_key_[old_val].first.empty()) {
                val_to_key_.erase(old_val);
                vals_.erase(val_iter);
            }
        } else {
            if (dif < 0) return; // increase no exist. do nothing.
            new_val = 1;
            if (vals_.empty() || vals_.back() != 1) {
                vals_.push_back(1);
            }
            new_val_iter = --vals_.end();
        }

        if (new_val == 0) {
            key_to_val_.erase(key);
            vals_.pop_back();
        } else {
            key_to_val_[key].first = new_val;
            auto& key_list = val_to_key_[new_val].first;
            key_to_val_[key].second = key_list.insert(key_list.end(), key);
            val_to_key_[new_val].second = new_val_iter;
        }
    }

public:
    /** Initialize your data structure here. */
    AllOne() {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        inc_or_dec(key, 1);
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        inc_or_dec(key, -1);
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return !vals_.empty() ? val_to_key_[vals_.front()].first.back() : "";
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return !vals_.empty() ? val_to_key_[vals_.back()].first.back() : "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */