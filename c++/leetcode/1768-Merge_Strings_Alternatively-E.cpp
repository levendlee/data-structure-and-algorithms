class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        const int n1 = word1.size(), n2 = word2.size();
        int i = 0, j = 0, k = 0;
        string res(n1 + n2, ' ');
        while (i < n1 || j < n2) {
            if (i == n1 || (j < n2) && (k % 2)) {
                res[k++] = word2[j++];
            } else {
                res[k++] = word1[i++];
            }
        }
        return res;
    }
};
