// 380 Insert Delete GetRandom O(1)
// https://leetcode.com/problems/insert-delete-getrandom-o1

// version: 1; create time: 2020-01-27 21:27:35;
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


// 2023/09/10
class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (index_map_.count(val)) {
            return false;
        }
        storage_vec_.push_back(val);
        index_map_[val] = storage_vec_.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!index_map_.count(val)) {
            return false;
        }
        int index = index_map_[val];
        int back_val = storage_vec_.back();
        std::swap(storage_vec_[index], storage_vec_.back());
        std::swap(index_map_[val], index_map_[back_val]);
        storage_vec_.pop_back();
        index_map_.erase(val);
        return true;
    }
    
    int getRandom() {
        int pick = std::rand() % storage_vec_.size();
        return storage_vec_[pick];
    }

private:
    vector<int> storage_vec_;
    unordered_map<int, int> index_map_;
};
