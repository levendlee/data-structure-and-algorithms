class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        const int n = seats.size();
        /*
        vector<int> ldist(n, 0);
        int dist = n;
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 0) {
                ldist[i] = dist++;
            } else {
                dist = 1;
            }
        }
        dist = n;
        int max_dist = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (seats[i] == 0) {
                max_dist = std::max(max_dist, std::min(ldist[i], dist++));
            } else {
                dist = 1;
            }
        }
        */
        int max_dist = 0;
        int last = -1;
        for (int i = 0; i < n; ++i) {
            if (seats[i]) {
                int dist = last < 0 ? i : (i - last) / 2;
                max_dist = std::max(max_dist, dist);
                last = i;
            }
        }
        max_dist = std::max(max_dist, (n - last - 1));
        return max_dist;
    }
};