// 705 Design HashSet
// https://leetcode.com/problems/design-hashset

// version: 1; create time: 2020-01-26 22:24:39;
class MyHashSet {
private:
    int bits_;
    vector<list<int>> vvec_;

    int calc_hash(int key) {
        int hash_key = 0;
        for (int i = 0; i < (8 * sizeof(int) / bits_); ++i) {
            hash_key ^= key;
            key >>= bits_;
        }
        return hash_key & ((1 << bits_) - 1);
    }

public:
    /** Initialize your data structure here. */
    MyHashSet() : bits_(5), vvec_(32) {

    }

    void add(int key) {
        auto& vec = vvec_[calc_hash(key)];
        if (std::find(vec.begin(), vec.end(), key) == vec.end()) {
            vec.push_back(key);
        }
    }

    void remove(int key) {
        auto& vec = vvec_[calc_hash(key)];
        auto iter = std::find(vec.begin(), vec.end(), key);
        if (iter != vec.end()) {
            vec.erase(iter);
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto& vec = vvec_[calc_hash(key)];
        return std::find(vec.begin(), vec.end(), key) != vec.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
