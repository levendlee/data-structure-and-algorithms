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