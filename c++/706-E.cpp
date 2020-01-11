class MyHashMap {
private:
    int bits_;
    vector<list<pair<int, int>>> hashmap_;

public:
    /** Initialize your data structure here. */
    MyHashMap() : bits_(5) {
        hashmap_.resize(1 << 5);
    }

    int getHashKey(int key) {
        int hash = 0;
        for (int i = 0; i < 32; i += bits_) {
            hash = hash ^ (key >> i);
        }
        return hash & ((1 << bits_) - 1);
    }

    auto& getList(int key) {
        return hashmap_[getHashKey(key)];
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int hashkey = getHashKey(key);
        auto& plist = hashmap_[hashkey];
        for (auto& p : plist) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        plist.push_back({key, value});
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hashkey = getHashKey(key);
        auto& plist = hashmap_[hashkey];
        for (auto& p : plist) {
            if (p.first == key) {
                return p.second;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hashkey = getHashKey(key);
        auto& plist = hashmap_[hashkey];

        auto remove_iter = plist.end();
        for (auto iter = plist.begin(); iter != plist.end(); ++iter) {
            if (iter->first == key) {
                remove_iter = iter;
                break;
            }
        }
        if (remove_iter != plist.end()) {
            plist.erase(remove_iter);
        }
    }
};