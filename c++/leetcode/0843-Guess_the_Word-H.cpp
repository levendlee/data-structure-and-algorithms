// 843 Guess the Word
// https://leetcode.com/problems/guess-the-word

// version: 1; create time: 2020-02-17 21:58:17;
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


// 2023/09/09
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        auto count_matches = [](const string& s0, const string& s1) {
            int cnt = 0;
            for (int i = 0; i < 6; ++i) {
                cnt += s0[i] == s1[i];
            }
            return cnt;
        };

        const int num_words = words.size();
        std::vector<std::vector<std::vector<int>>> num_matches(num_words, std::vector<std::vector<int>>(7));
        for (int i = 0; i < num_words; ++i) {
            for (int j = i; j < num_words; ++j) {
                int cnt = count_matches(words[i], words[j]);
                num_matches[i][cnt].push_back(j);
                num_matches[j][cnt].push_back(i);
            }
        }

        std::vector<int> candidates(num_words);
        for (int i = 0; i < num_words; ++i) {
            candidates[i] = i;
        }
        int num_guess = 0;
        while (++num_guess <= 30) {
            int pick_idx = (std::rand() + 1) % candidates.size();
            int pick_num = candidates[pick_idx];
            int num_match = master.guess(words[pick_num]);
            if (num_match == 6) {
                return;
            }
            std::vector<int> new_candidates;
            std::set_intersection(candidates.begin(), candidates.end(),
                                 num_matches[pick_num][num_match].begin(),
                                 num_matches[pick_num][num_match].end(),
                                 std::back_inserter(new_candidates));
            candidates = std::move(new_candidates);
        }


    }
};
