// 352 Data Stream as Disjoint Intervals
// https://leetcode.com/problems/data-stream-as-disjoint-intervals

// version: 1; create time: 2020-02-06 22:36:38;
class SummaryRanges {
private:
    map<int, int> ranges_;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {
        //std::cout << "Add " << val << "\n";
        auto nex = ranges_.lower_bound(val);
        auto nex_s = nex != ranges_.end() ? nex->first : INT_MAX;
        auto nex_e = nex != ranges_.end() ? nex->second : INT_MAX;
        auto pre_s = nex != ranges_.begin() ? prev(nex)->first : INT_MIN;
        auto pre_e = nex != ranges_.begin() ? prev(nex)->second : INT_MIN;
        if (val == nex_s || val <= pre_e) return;
        if (val == pre_e + 1 && val == nex_s - 1) {
            ranges_[pre_s] = nex_e;
            ranges_.erase(nex_s);
        } else if (val == nex_s - 1) {
            ranges_.erase(nex);
            ranges_[val] = nex_e;
        } else if (val == pre_e + 1) {
            ranges_.erase(prev(nex));
            ranges_[pre_s] = val;
        } else {
            ranges_[val] = val;
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;
        for (const auto& rng : ranges_) {
            intervals.push_back({rng.first, rng.second});
        }
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

//

class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        /*
        if (tree_.empty()) {
            tree_[value] = value;
            return;
        }
        */
        auto iter = tree_.lower_bound(value);
        int start0, end0, start1, end1;
        if (iter == tree_.end()) {
            start1 = value;
            end1 = value;
        } else {
            start1 = iter->first;
            end1 = iter->second;
            if (start1 == value) return;
        }
        if (iter == tree_.begin()) {
            start0 = value;
            end0 = value;
        } else {
            --iter;
            start0 = iter->first;
            end0 = iter->second;
            if (end0 >= value) return;
        }        
        if (end0 + 1 == value && value + 1 == start1) {
            tree_.erase(start1);
            tree_[start0] = end1;
        } else if (end0 + 1 == value) {
            tree_[start0] = value;
        } else if (value + 1 == start1) {
            tree_.erase(start1);
            tree_[value] = end1;
        } else {
            tree_[value] = value;
        }
        
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (const auto& [start, end] : tree_) {
            res.push_back({start, end});
        }
        return res;
    }

private:
    std::map<int, int> tree_;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
