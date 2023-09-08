class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        std::unordered_set<int> locs;
        for (int n : nums) {
            locs.insert(n);
        }
        for (int i = 0; i < moveFrom.size(); ++i) {
            locs.erase(moveFrom[i]);
            locs.insert(moveTo[i]); 
        }
        std::vector<int> res(locs.begin(), locs.end());
        std::sort(res.begin(), res.end());
        return res;
    }
};
