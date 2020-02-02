class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        const int n1 = nums1.size();
        const int n2 = nums2.size();

        vector<vector<int>> res;
        if (n1 == 0 || n2 == 0) return res;

        priority_queue<vector<int>> pq;
        for (int i = 0; i < n1; ++i) {
            pq.push({-(nums1[i] + nums2[0]), i, 0});
        }

        // O(KlogN)
        while (k-- && !pq.empty()) {
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();
            res.push_back({nums1[i], nums2[j]});
            if (j + 1 < n2) {
                pq.push({-nums1[i]-nums2[j+1], i, j + 1});
            }
        }
        return res;
    }
};