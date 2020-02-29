// 444 Sequence Reconstruction
// https://leetcode.com/problems/sequence-reconstruction

// version: 1; create time: 2020-02-15 22:33:07;
class Solution {
public:
    bool tpSort(unordered_map<int, vector<int>>& edges,
                vector<bool>& perm,
                vector<bool>& temp,
                int cur) {
        if (temp[cur]) return false;
        if (perm[cur]) return true;
        temp[cur] = true;
        for (const auto& pre : edges[cur]) {
            if (!tpSort(edges, perm, temp, pre)) return false;
        }
        temp[cur] = false;
        perm[cur] = true;
        return true;
    }

    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        unordered_map<int, vector<int>> edges;
        for (const auto& seq: seqs) {
            const int n = seq.size();
            for (int i = 1; i < n; ++i) {
                edges[seq[i]].push_back(seq[i-1]);
            }
        }

        const int n = org.size();
        for (const auto & seq : seqs) {
            for (const auto& s : seq) {
                if (s <= 0 || s > n) return false;
            }
        }

        if (n == 1) {
            for (const auto& s : seqs) {
                if (s.size() == 1 && s[0] == org[0]) return true;
            }
            return false;
        }

        for (int i = n - 1; i > 0; --i) {
            auto pre = org[i-1];
            auto cur = org[i];
            auto& vec = edges[cur];
            if (find(vec.begin(), vec.end(), pre) == vec.end()) {
                return false;
            }
        }

        vector<bool> temp(n, false), perm(n, false);
        for (int i = 0; i < n; ++i) {
            if (!tpSort(edges, perm, temp, i)) return false;
        }
        return true;
    }
};
