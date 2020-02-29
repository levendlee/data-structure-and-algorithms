// 244 Shortest Word Distance II
// https://leetcode.com/problems/shortest-word-distance-ii

// version: 1; create time: 2020-02-08 20:10:11;
// Assume M words, N unique words.
// This is construction : time complexity O(MN). space complexity O(M^2).
// query: time complexity O(1).
class WordDistance {
private:
    vector<vector<int>> dist_;
    unordered_map<string, int> index_;

public:
    WordDistance(vector<string>& words) {
        const int n = words.size();
        for (const auto& w : words) {
            if (!index_.count(w)) {
                index_[w] = index_.size();
            }
        }
        const int m = index_.size();
        dist_ = vector<vector<int>>(m, vector<int>(m, INT_MAX));
        vector<int> last(m, -1);
        for (int i = 0; i < n; ++i) {
            auto idx = index_[words[i]];
            auto pre = last[idx];
            for (int k = pre + 1; k < i; ++k) {
                auto idx2 = index_[words[k]];
                dist_[idx2][idx] = dist_[idx][idx2] = std::min(dist_[idx][idx2], i - k);
            }
            last[idx] = i;
        }
    }

    int shortest(string word1, string word2) {
        return dist_[index_[word1]][index_[word2]];
    }
};

// construction: time complexity O(M). space complexity O(M).
// query: time complexity O(M/N);
class WordDistance {
private:
    unordered_map<string, vector<int>> indices_;

public:
    WordDistance(vector<string>& words) {
        const int n = words.size();
        for (int i = 0; i < n; ++i) {
            indices_[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        auto& idx1 = indices_[word1];
        auto& idx2 = indices_[word2];
        int n1 = idx1.size(), n2 = idx2.size();
        int i = 0, j = 0, res = INT_MAX;
        while (i < n1 && j < n2) {
            res = std::min(res, abs(idx2[j] - idx1[i]));
            if (idx1[i] > idx2[j]) {
                j++;
            } else {
                i++;
            }
        }
        return res;
    }
};
/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
