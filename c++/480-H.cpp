class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;

        const int n = nums.size();
        set<pair<int,int>> ltree, rtree;
        for (int i = 0; i < n; ++i) {
            if (!rtree.empty() && nums[i] >= rtree.begin()->first ||
                !ltree.empty() && nums[i] > ltree.rbegin()->first) {
                rtree.insert({nums[i], i});
            } else {
                ltree.insert({nums[i], i});
            }
            if (i >= k - 1) {
                while (rtree.size() > ltree.size() + 1) {
                    auto iter = rtree.begin();
                    ltree.insert(*iter);
                    rtree.erase(iter);
                }
                while (ltree.size() > rtree.size() + 1) {
                    auto iter = --ltree.end();
                    rtree.insert(*iter);
                    ltree.erase(iter);
                }

                if (k % 2) {
                    res.push_back(rtree.size() > ltree.size() ? rtree.begin()->first : ltree.rbegin()->first);
                } else {
                    res.push_back(((double)(ltree.rbegin()->first) + rtree.begin()->first) / 2.0);
                }

                auto expired = std::make_pair(nums[i+1-k], i+1-k);
                if (rtree.count(expired)) {
                    rtree.erase(expired);
                } else {
                    ltree.erase(expired);
                }
            }
        }

        return res;
    }
};