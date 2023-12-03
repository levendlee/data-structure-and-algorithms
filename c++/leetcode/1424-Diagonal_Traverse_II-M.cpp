class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        /*
        vector<int> res;
        for (int r = 0; r < n; ++r) {
            int i = r;
            int j = 0;
            while (i >= 0) {
                if (nums[i].size() >= j + 1) {
                    res.push_back(nums[i][j]);
                }
                --i;
                ++j;
            }
        }
        int c = 1;
        while (true) {
            bool inserted = false;
            int i = n - 1;
            int j = c;
            while (i >= 0) {
                if (nums[i].size() >= j + 1) {
                    res.push_back(nums[i][j]);
                    inserted = true;
                }
                --i;
                ++j;
            }
            ++c;
            if (!inserted) break;
        }
        */
        const int m = nums.size();
        unordered_map<int, vector<int>> traverse;
        for (int i = m - 1; i >= 0; --i) {
            int n = nums[i].size();
            for (int j = n - 1; j >= 0; --j) {
                int id = j - (m - 1 - i);
                traverse[id].push_back(nums[i][j]); 
            }
        }
        vector<int> ids;
        for (const auto& [id, vec] : traverse) {
            ids.push_back(id);
        }
        sort(ids.begin(), ids.end());
        vector<int> res;
        for (const auto id : ids) {
            res.insert(res.end(), traverse[id].begin(), traverse[id].end());
        }
        return res;
    }
};
