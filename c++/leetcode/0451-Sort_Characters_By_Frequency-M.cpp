class Solution {
public:
    string frequencySort(string s) {
        /*
        int freq[62];
        fill(freq, freq + 62, 0);
        auto to_index = [](char c) {
            if (isupper(c)) {
                return c - 'A';
            } else if (islower(c)){
                return c - 'a' + 26;
            } else {
                return c - '0' + 52;
            }
        };
        for (char c : s) {
            ++freq[to_index(c)];
        }
        sort(s.begin(), s.end(), [&](const char& a, const char& b) {
            return freq[to_index(a)] > freq[to_index(b)] || (
                freq[to_index(a)] == freq[to_index(b)] && a > b
            );
        });
        */
        int freq[256];
        fill(freq, freq + 256, 0);
        for (char c : s) {
            ++freq[c];
        }

        int indices[256];
        iota(indices, indices + 256, 0);
        sort(indices, indices + 256, [&](int i, int j) { return freq[i] > freq[j]; });

        string res;
        for (int i = 0; i < 256; ++i) {
            if (!freq[indices[i]]) break;
            res += string(freq[indices[i]], char(indices[i]));
        }
        return res;
    }
};