class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int index[26];
        for (int i = 0; i < 26; ++i) {
            index[keyboard[i] - 'a'] = i;
        }
        int pos = 0;
        int dist = 0;
        for (int i = 0; i < word.size(); ++i) {
            dist += abs(index[word[i] - 'a'] - pos);
            pos = index[word[i] - 'a'];
        }
        return dist;
    }
};