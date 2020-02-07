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