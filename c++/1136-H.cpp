class Solution {
public:
    int tpSort(const vector<vector<int>>& prereqs,
               vector<int>& perm,   // perm mark, records depth
               vector<bool>& temp,  // temp mark
               const int idx) {
        if (temp[idx]) {
            return -1;
        }
        if (perm[idx]) {
            return perm[idx];
        }
        temp[idx] = true;
        int depth = 1;
        for (const auto& pre : prereqs[idx]) {
            int pre_depth = tpSort(prereqs, perm, temp, pre);
            if (pre_depth == -1) return -1;
            depth = std::max(depth, pre_depth + 1);
        }
        temp[idx] = false;
        perm[idx] = depth;
        return depth;
    }

    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<vector<int>> prereqs(N);
        for (const auto& rel : relations) {
            prereqs[rel[1] - 1].push_back(rel[0] - 1);
        }

        vector<int> perm(N, 0);
        vector<bool> temp(N, false);
        int max_depth = 0;
        for (int i = 0; i < N; ++i) {
            int depth = tpSort(prereqs, perm, temp, i);
            if (depth == -1) return -1;
            max_depth = std::max(max_depth, depth);
        }

        return max_depth;
    }
};