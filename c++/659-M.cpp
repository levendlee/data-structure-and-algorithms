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