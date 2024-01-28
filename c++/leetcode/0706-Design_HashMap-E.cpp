// 706 Design HashMap
// https://leetcode.com/problems/design-hashmap

// version: 1; create time: 2020-01-11 16:55:22;
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

//

class MyHashMap {
public:
    MyHashMap() {
        addr_bits_ = 8;
        storage_.resize(1 << addr_bits_);
    }
    
    void put(int key, int value) {
        int hash_key = hash(key);
        auto& array = storage_[hash_key];
        for (auto& p : array) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        array.push_back({key, value});
    }
    
    int get(int key) {
        int hash_key = hash(key);
        auto& array = storage_[hash_key];
        for (auto& p : array) {
            if (p.first == key) {
                return p.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int hash_key = hash(key);
        auto& array = storage_[hash_key];
        for (int i = 0; i < array.size(); ++i) {
            if (array[i].first == key) {
                swap(array[i], array.back());
                array.pop_back();
                return;
            }
        }
    }

private:
    int hash(int key) {
        int hashed = 0;
        for (int shift = 0; shift < 32; shift += addr_bits_) {
            hashed ^= (key >> shift) & ((1 << addr_bits_) - 1);
        }
        return hashed;
    }

    int addr_bits_;
    vector<vector<pair<int, int>>> storage_;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */