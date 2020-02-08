class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        const int n = matrix.size();
        priority_queue<int> pq;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pq.size() == k && pq.top() < matrix[i][j]) continue;
                pq.push(matrix[i][j]);
                if (pq.size() > k) pq.pop();
            }
        }
        return pq.top();
    }
};