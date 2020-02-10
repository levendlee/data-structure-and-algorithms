class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int shortest = INT_MAX;
        int i = -1, j = -1;
        for (int k = 0; k < words.size(); ++k) {
            if (words[k] == word1) {
                i = k;
            } else if (words[k] == word2) {
                j = k;
            }
            if (i != -1 && j != -1) {
                shortest = std::min(abs(i - j), shortest);
            }
        }
        return shortest;
    }
};