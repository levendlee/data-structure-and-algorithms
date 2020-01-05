class Solution {
public:
    int atMost(vector<int>& A, int K) {
        const int n = A.size();
        unordered_map<int, int> count;
        int i = 0, j = 0;
        int cnt = 0;
        while (j < n) {
            ++count[A[j]];
            while (count.size() > K) {
                cnt += j - i;
                if (--count[A[i]] == 0) {
                    count.erase(A[i]);
                }
                ++i;
            }
            ++j;
        }
        while (i < j) {
            cnt += j - i;
            ++i;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& A, int K) {
        const int n = A.size();
        /*
        // Time Complexity O(N^2): TLE
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            unordered_set<int> unique;
            int kinds = 0;
            for (int j = i; j < n; ++j) {
                if (!unique.count(A[j])) {
                    if (kinds < K) {
                        unique.insert(A[j]);
                        ++kinds;
                    } else {
                        break;
                    }
                }
                cnt += kinds == K;
            }
        }
        */
        return atMost(A, K) - atMost(A, K - 1);
    }
};