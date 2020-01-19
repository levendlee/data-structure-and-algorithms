class Solution {
public:
    bool canTransform(string start, string end) {
        if (start.size() != end.size()) return false;

        const int n = start.size();
        // Relative order of 'R' and 'L' stay unchaged
        int i = 0, j = 0;
        while (i < n || j < n) {
            while (i < n && start[i] == 'X') ++i;
            while (j < n && end[j] == 'X') ++j;
            if (i == n && j == n) break;
            if (i == n || j == n || start[i] != end[j]) return false;
            ++i; ++j;
        }

        int sl = 0, sr = 0, el = 0, er = 0;
        for (int i = 0; i < n; ++i){
            sl += start[i] == 'L';
            sr += start[i] == 'R';
            el += end[i] == 'L';
            er += end[i] == 'R';
            if (sl > el) return false;
            if (sr < er) return false;
        }
        return true;
    }
};