class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        const int n = nums1.size();

        vector<int> indicies2(n, 0);
        iota(indicies2.begin(), indicies2.end(), 0);
        sort(indicies2.begin(), indicies2.end(),
            [&](int i, int j) { return nums2[i] < nums2[j]; });
        
        long long max_score = 0;
        priority_queue<int> scores;
        long long sum_score = 0;
        for (int i = n - 1; i >= 0; --i) {
            int idx = indicies2[i];
            scores.push(-nums1[idx]);
            sum_score += nums1[idx];
            if (scores.size() > k) {
                sum_score += scores.top();
                scores.pop();
            }
            if (scores.size() == k) {
                max_score = max(max_score, nums2[idx] * sum_score);
            }
        }

        return max_score;
    }
};
