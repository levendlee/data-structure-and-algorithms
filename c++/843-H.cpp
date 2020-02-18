/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int matchChars(const string& str0, const string& str1) {
        const int n = str0.size();
        int match = 0;
        for (int i = 0; i < n; ++i) {
            match += str0[i] == str1[i];
        }
        return match;
    }

    void findSecretWord(vector<string>& wordlist, Master& master) {
        const int n = wordlist.size();

        vector<vector<int>> match_cnts(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                match_cnts[i][j] = matchChars(wordlist[i], wordlist[j]);
            }
        }

        vector<int> candidates(n, 0);
        iota(candidates.begin(), candidates.end(), 0);

        while (true) {
            const int m = candidates.size();

            vector<int> max_cnts(m, 0);
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (i == j) continue;
                    max_cnts[i] = max(max_cnts[i], match_cnts[candidates[i]][candidates[j]]);
                }
            }

            int pick = candidates[max_element(max_cnts.begin(), max_cnts.end()) - max_cnts.begin()];
            auto match = master.guess(wordlist[pick]);
            if (match == wordlist[pick].size()) return;

            vector<int> n_candidates;
            for (int i = 0; i < m; ++i) {
                if (match_cnts[candidates[i]][pick] == match) {
                    n_candidates.push_back(candidates[i]);
                }
            }

            candidates = move(n_candidates);
        }
    }
};