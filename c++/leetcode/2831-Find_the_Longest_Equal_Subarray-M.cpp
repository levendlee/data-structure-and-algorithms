class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        const int n = nums.size();

        set<pair<int, int>> reverse_counter_set;
        unordered_map<int, set<pair<int, int>>::iterator> counter_map;
        auto update_counter = [&](int i, int value) {
            pair<int, int> count_to_num;
            if (counter_map.count(nums[i])) {
                auto iter = counter_map[nums[i]];
                count_to_num = *iter;
                reverse_counter_set.erase(iter);
                count_to_num.first += value;
            } else {
                count_to_num = {1, nums[i]};
            }
            counter_map[nums[i]] = reverse_counter_set.insert(count_to_num).first;
        };

        int longest = 0;
        int i = 0, j = 0;
        while (j < n) {
            update_counter(j++, 1);
            while (j - i - reverse_counter_set.rbegin()->first > k) {
                update_counter(i++, -1);
            }
            longest = std::max(longest, reverse_counter_set.rbegin()->first);
        }
        return longest;

    }
};

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        unordered_map<int, vector<int>> num_to_indicies;
        for (int i = 0; i < nums.size(); ++i) {
            num_to_indicies[nums[i]].push_back(i);
        }
        int longest = 1;
        for (const auto& [n, indicies] : num_to_indicies) {
            if (indicies.size() <= 1) {
                continue;
            }
            int i = 0, j = 0, others = 0;
            while (j + 1 < indicies.size()) {
                others += indicies[j + 1] - indicies[j] - 1;
                ++j;
                while (others > k) {
                    others -= indicies[i + 1] - indicies[i]  - 1;
                    ++i;
                }
                longest = std::max(longest, j - i + 1);
            }
        }
        return longest;
    }
};
