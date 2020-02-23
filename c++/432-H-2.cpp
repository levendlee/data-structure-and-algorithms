class AllOne {
// Buggy
private:
    list<int> cnts_;
    unordered_map<string, list<int>::iterator> key2cnt_;
    unordered_map<int, unordered_set<string>> cnt2key_;

public:
    /** Initialize your data structure here. */
    AllOne() {
        cnts_.push_back(0);
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        auto iter = key2cnt_.count(key) ? key2cnt_[key] : cnts_.begin();
        auto cnt = *iter;
        if (next(iter) == cnts_.end() || *next(iter) != cnt + 1) {
            iter = cnts_.insert(next(iter), cnt + 1);
        } else {
            ++iter;
        }
        if (cnt > 0) {
            cnt2key_[cnt].erase(key);
            if (cnt2key_[cnt].empty()) {
                cnt2key_.erase(cnt);
                cnts_.erase(prev(iter));
            }
        }
        key2cnt_[key] = iter;
        cnt2key_[*iter].insert(key);
        //cout << cnts_.size() << "," << cnts_.front() << "," << cnts_.back() << "\n";
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (key2cnt_.count(key) == 0) return;
        auto iter = key2cnt_[key];
        auto cnt = *iter;
        if (iter == cnts_.begin() || *prev(iter) != cnt - 1) {
            iter = cnts_.insert(iter, cnt - 1);
        } else {
            --iter;
        }
        cnt2key_[cnt].erase(key);
        if (cnt2key_[cnt].empty()) {
            cnt2key_.erase(cnt);
            cnts_.erase(next(iter));
        }
        if (*iter == 0) return;
        key2cnt_[key] = iter;
        cnt2key_[*iter].insert(key);
        //cout << cnts_.size() << "," << cnts_.front() << "," << cnts_.back() << "\n";
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return cnts_.size() == 1 ? "" : *cnt2key_[cnts_.back()].begin();
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return cnts_.size() == 1? "" : *cnt2key_[*++cnts_.begin()].begin();
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