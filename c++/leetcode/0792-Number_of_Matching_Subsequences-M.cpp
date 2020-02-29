// 792 Number of Matching Subsequences
// https://leetcode.com/problems/number-of-matching-subsequences

// version: 1; create time: 2020-01-27 22:26:51;
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        // O(MN)
        /*
        int cnt = 0;
        for (int i = 0; i < words.size(); ++i) {
            int k = 0;
            for (int j = 0; j < S.size(); ++j) {
                if (words[i][k] == S[j]) ++k;
                if (k == words[i].size()) break;
            }
            cnt += k == words[i].size();
            //std::cout << i << "," << cnt << "\n";
        }
        */

        // O(M + N)
        vector<queue<pair<int,int>>> qvec(26);
        for (int i = 0; i < words.size(); ++i) {
            const auto idx = words[i][0] - 'a';
            qvec[idx].push({i, 0});
        }
        int cnt = 0;
        for (int i = 0; i < S.size(); ++i) {
            auto& q = qvec[S[i] - 'a'];
            const auto size = q.size();
            for (int t = 0; t < size; ++t) {
                const auto j = q.front().first;
                const auto k = q.front().second;
                q.pop();
                if (k == words[j].size() - 1) {
                    ++cnt;
                } else {
                    qvec[words[j][k+1] - 'a'].push({j, k + 1});
                }
            }
        }

        return cnt;
    }
};
