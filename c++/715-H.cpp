// Good memory usage. Bad runtime.
class RangeModule {
private:
    std::map<int,int> bst_;

public:
    RangeModule() {

    }

    // K: number of intervals
    // Time: O(logK)
    void addRange(int left, int right) {
        auto p1 = bst_.insert({left, 1});
        p1.first->second += !p1.second;

        auto p2 = bst_.insert({right, -1});
        p2.first->second -= !p2.second;
    }

    // Time: O(K)
    bool queryRange(int left, int right) {
        auto overlaps = 0;

        auto insert_left = bst_.insert({left, 0}).second;
        auto insert_right = bst_.insert({right, 0}).second;

        bool cover = true;
        for (auto& p: bst_) {
            overlaps += p.second;

            if ((overlaps <= 0) && (p.first >= left && p.first < right)) {
                cover = false;
                break;
            }
        }

        if (insert_left) bst_.erase(left);
        if (insert_right) bst_.erase(right);

        return cover;
    }

    // Time: O(K)
    void removeRange(int left, int right) {
        auto p1 = bst_.insert({left, 0});
        auto p2 = bst_.insert({right, 0});

        int overlaps = 0;
        for (auto iter = bst_.begin(); iter != p1.first; ++iter) {
            overlaps += iter->second;
        }
        p1.first->second = -overlaps;

        overlaps = 0;
        for (auto iter = --bst_.end(); iter != p2.first; --iter) {
            overlaps += iter->second;
        }
        p2.first->second = -overlaps;

        std::vector<int> removes;
        for (auto iter = ++p1.first; iter != p2.first; ++iter) {
            removes.push_back(iter->first);
        }
        for (auto r : removes) {
            bst_.erase(r);
        }
    }
};