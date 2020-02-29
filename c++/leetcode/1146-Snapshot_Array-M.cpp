// 1146 Snapshot Array
// https://leetcode.com/problems/snapshot-array

// version: 1; create time: 2019-12-12 20:22:57;
/*
class SnapshotArray {
private:
    int snap_id_;
    std::map<int, int> changes_;
    std::vector<std::map<int, int>> tree_vec_;

public:
    SnapshotArray(int length) : snap_id_(0), changes_(), tree_vec_(length) {

    }

    void set(int index, int val) {
        changes_[index] = val;
    }

    int snap() {
        for (const auto& p : changes_) {
            tree_vec_[p.first][snap_id_] = p.second;
        }
        changes_.clear();
        return snap_id_++;
    }

    int get(int index, int snap_id) {
        auto iter = tree_vec_[index].upper_bound(snap_id);
        if (iter == tree_vec_[index].begin()) {
            return 0;
        } else {
            return (--iter)->second;
        }
    }
};
*/

class SnapshotArray {
private:
    int snap_id_;
    std::map<std::pair<int, int>, int> hist_;

public:
    SnapshotArray(int length) : snap_id_(0), hist_() {

    }

    void set(int index, int val) {
        auto hist_index = std::make_pair(index, snap_id_);
        hist_[hist_index] = val;
    }

    int snap() {
        return snap_id_++;
    }

    int get(int index, int snap_id) {
        auto hist_index = std::make_pair(index, snap_id);
        auto iter = hist_.upper_bound(hist_index);
        if (iter == hist_.begin()) {
            return 0;
        }
        --iter;
        if (iter->first.first != index) {
            return 0;
        } else {
            return iter->second;
        }
    }
};
