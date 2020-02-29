// 659 Split Array into Consecutive Subsequences
// https://leetcode.com/problems/split-array-into-consecutive-subsequences

// version: 1; create time: 2019-10-26 21:03:10;
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        const int n = nums.size();

        std::queue<int> seq_starts;
        int i = 0;
        while (i < n) {
            int j = i + 1;
            while ((j < n) && (nums[j] == nums[i])) ++j;
            int cnt = j - i;

            while (seq_starts.size() < cnt) {
                seq_starts.push(nums[i]);
            }

            while (seq_starts.size() > cnt) {
                auto start = seq_starts.front();
                seq_starts.pop();
                if (nums[i] - start < 3) {
                    return false;
                }
            }

            if ((j >= n) || (nums[i] + 1 != nums[j])) {
                while (!seq_starts.empty()) {
                    if (nums[i] - seq_starts.front() < 2) {
                        return false;
                    }
                    seq_starts.pop();
                }
            }

            i = j;
        }

        return true;
    }
};


// version: 1; create time: 2020-02-17 21:34:30;
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        /*
        unordered_map<int, list<int>> tail_size;
        for (const auto& n : nums) {
            if (tail_size.count(n - 1) && !tail_size[n-1].empty()) {
                auto size = tail_size[n-1].front(); tail_size[n-1].pop_front();
                tail_size[n].push_back(size + 1);
            } else {
                tail_size[n].push_front(1);
            }
        }
        for (const auto& p : tail_size) {
            for (const auto& s : p.second) {
                if (s < 3) return false;
            }
        }
        */
        unordered_map<int, int> left;
        unordered_map<int, int> end;
        for (const auto& n : nums) {
            ++left[n];
        }
        for (const auto& n : nums) {
            if (!left[n]) continue;
            --left[n];
            if (end[n - 1] > 0) {
                end[n - 1] -= 1;
                end[n] += 1;
            } else if (left[n + 1] > 0 && left[n + 2] > 0) {
                left[n + 1] -= 1;
                left[n + 2] -= 1;
                end[n + 2] += 1;
            } else {
                return false;
            }
        }
        return true;
    }
};
