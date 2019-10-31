class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        unordered_map<int> hash;
        for (auto& a : A) {
            hash[a]++;
        }
        int largest_number = -1;
        for (auto& p : hash) {
            if (p.second == 1) {
                largest_number = std::max(largest_number, p.first);
            }
        }
        return largest_number;
    }
};