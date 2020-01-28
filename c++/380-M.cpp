class RandomizedSet {
private:
    std::vector<int> vals_;
    unordered_map<int, int> val_to_idx_;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (!val_to_idx_.count(val)) {
            val_to_idx_[val] = vals_.size();
            vals_.push_back(val);
            return true;
        } else {
            return false;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (val_to_idx_.count(val)) {
            const auto idx = val_to_idx_[val];
            val_to_idx_[vals_.back()] = idx;
            std::swap(vals_[idx], vals_.back());
            vals_.pop_back();
            val_to_idx_.erase(val);
            return true;
        } else {
            return false;
        }
    }

    /** Get a random element from the set. */
    int getRandom() {
        return vals_[random() % vals_.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */