class Solution {
public:
    int pathSum(vector<int>& nums) {
        auto decompose = [](int num) -> tuple<int, int, int> {
            return {num / 100, (num % 100) / 10, num % 10};
        };

        int max_d = get<0>(decompose(nums.back()));
        int sum = 0;
        vector<vector<int>> values(4, vector<int>(8, -1));
        for (int num: nums) {
            auto [d, p, v] = decompose(num);
            values[d - 1][p - 1] = v;
        }

        for (int num : nums) {
            auto [d, p, v] = decompose(num);
            if (d == 4 || values[d][p * 2 - 2] == -1 && values[d][p * 2 - 1] == -1) {
                while (d) {
                    sum += values[d - 1][p - 1];
                    --d;
                    p = (p - 1) / 2 + 1;
                }
            }
        }
        return sum;
    }
};
