// 480 Sliding Window Median
// https://leetcode.com/problems/sliding-window-median

// version: 1; create time: 2020-01-29 21:26:13;
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

//

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        set<pair<int, int>> ltree, rtree;
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            auto to_insert = make_pair(nums[i], i);

            // Records value and index.
            if (rtree.empty() || rtree.begin()->first > nums[i]) {
                ltree.insert(to_insert);
            } else {
                rtree.insert(to_insert);
            }

            // Removes old element.
            if (i >= k) {
                auto to_remove = make_pair(nums[i - k], i - k);
                auto iter = ltree.find(to_remove);
                if (iter != ltree.end()) {
                    ltree.erase(iter);
                } else {
                    rtree.erase(to_remove);
                }
            }
    
            // Rebalances two trees.
            while (ltree.size() > rtree.size() + 1) {
                auto iter = --ltree.end();
                rtree.insert(*iter);
                ltree.erase(iter);
            }
            while (ltree.size() < rtree.size()) {
                auto iter = rtree.begin();
                ltree.insert(*iter);
                rtree.erase(iter);
            }

            // Find median.
            if (i >= k - 1) {
                double median = k & 0x1 ? ltree.rbegin()->first : ((double)ltree.rbegin()->first + (double)rtree.begin()->first) / 2.0;
                res.push_back(median);
            }
        }
        return res;
    }
};
