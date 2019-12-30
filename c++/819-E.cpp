class Solution {
public:
    string extractWord(const string& s, int i, int j) {
        string res;
        for (int k = i; k < j; ++k) {
            res.push_back(tolower(s[k]));
        }
        return res;
    }

    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> counter;
        const int n = paragraph.size();
        int i = 0, j = 0;
        while (j <= n) {
            if (j == n || !isalpha(paragraph[j])) {
                if (j > i) {
                    const auto word = extractWord(paragraph, i, j);
                    ++counter[word];
                }
                i = j + 1;
            }
            ++j;
        }
        for (const auto& s : banned) {
            counter.erase(s);
        }
        string commonWord;
        int freq = 0;
        for (const auto& p : counter) {
            if (p.second > freq) {
                commonWord = p.first;
                freq = p.second;
            }
        }
        return commonWord;
    }
};