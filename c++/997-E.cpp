class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trustA(N, 0);
        vector<int> trustB(N, 0);
        for (const auto& rel : trust) {
            ++trustA[rel[0]-1];
            ++trustB[rel[1]-1];
        }
        int judge = -1;
        for (int i = 0; i < N; ++i) {
            if (trustA[i] == 0 && trustB[i] == N - 1) {
                if (judge == -1) {
                    judge = i + 1;
                } else {
                    return -1;
                }
            }
        }
        return judge;
    }
};