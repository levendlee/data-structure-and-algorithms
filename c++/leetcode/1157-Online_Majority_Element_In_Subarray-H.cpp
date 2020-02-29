// 1157 Online Majority Element In Subarray
// https://leetcode.com/problems/online-majority-element-in-subarray

// version: 1; create time: 2019-12-22 11:10:57;
// reach time limit
/*
class MajorityChecker {
private:
    int n_;
    std::vector<int> arr_;
    std::unordered_map<int, std::map<int, int>> seg_trees_;

public:
    void buildSegmentTrees(std::map<int, int>& par_cnt_tree, const int s, const int e)
    {
        if (e - s <= 0) {
            for (int i = s; i <= e; ++i) {
                ++par_cnt_tree[arr_[i]];
            }
        } else {
            int mid = (s + e) / 2;

            std::map<int, int> cur_cnt_tree;
            buildSegmentTrees(cur_cnt_tree, s, mid);
            buildSegmentTrees(cur_cnt_tree, mid + 1, e);

            int idx = s * n_ + e;
            for (const auto& val_n_cnt : cur_cnt_tree) {
                par_cnt_tree[val_n_cnt.first] += val_n_cnt.second;
            }
            seg_trees_[idx] = std::move(cur_cnt_tree);
        }
    }

    void searchSegmentTrees(std::map<int, int>& cnt_tree,
                            const int s, const int e, const int ss, const int se) {
        if (se - ss <= 0) {
            // small range, doesn't bother using tree
            for (int i = std::max(s, ss); i <= std::min(e, se); ++i) {
                ++cnt_tree[arr_[i]];
            }
        } else {
            // query out of range
            if (e < ss || s > se) return;

            if (s <= ss && e >= se) {
                // query contains range
                int idx = ss * n_ + se;
                for (const auto& val_n_cnt : seg_trees_[idx]) {
                    cnt_tree[val_n_cnt.first] += val_n_cnt.second;
                }
            } else {
                // query paritially overlaps with range
                int mid = (ss + se) / 2;
                searchSegmentTrees(cnt_tree, s, e, ss, mid);
                searchSegmentTrees(cnt_tree, s, e, mid + 1, se);
            }
        }
    }

    MajorityChecker(vector<int>& arr) {
        n_ = arr.size();
        arr_ = arr;
        std::map<int, int> cur_cnt_tree;
        buildSegmentTrees(cur_cnt_tree, 0, arr.size() - 1);
        seg_trees_[n_] = cur_cnt_tree;
    }

    int query(int left, int right, int threshold) {
        std::map<int, int> cnt_tree;
        searchSegmentTrees(cnt_tree, left, right, 0, n_ - 1);
        for (const auto& val_n_cnt : cnt_tree) {
            if (val_n_cnt.second >= threshold) {
                return val_n_cnt.first;
            }
        }
        return -1;

    }
};
*/

class MajorityChecker {
private:
    std::vector<int>& arr_;
    std::unordered_map<int, std::vector<int>> pos_vecs_;

public:
    MajorityChecker(vector<int>& arr) : arr_(arr) {
        const int n = arr.size();
        for (int i = 0; i < n; ++i) {
            pos_vecs_[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int threshold) {
        for (int k = 0; k < 10; ++k) {
            int idx = left + rand() % (right - left + 1);
            auto val = arr_[idx];
            const auto& pv = pos_vecs_[arr_[idx]];
            auto l_iter = std::lower_bound(pv.begin(), pv.end(), left);
            auto r_iter = std::upper_bound(pv.begin(), pv.end(), right);
            if (r_iter - l_iter >= threshold) {
                return arr_[idx];
            }
        }
        return -1;
    }
};
