class Solution {
public:
    int maxVowels(string s, int k) {
        char vowels[] = {'a', 'e', 'i', 'o', 'u'};
        bool is_vowels[26] = {false};
        for (char c : vowels) {
            is_vowels[c - 'a'] = true;
        }

        int i = 0, j = 0, num_vowels = 0;
        while (j < k) {
            num_vowels += is_vowels[s[j++] - 'a'];
        }
        int max_num_vowels = num_vowels;
        while (j < s.size()) {
            num_vowels += is_vowels[s[j++] - 'a'];
            num_vowels -= is_vowels[s[i++] - 'a'];
            max_num_vowels = max(max_num_vowels, num_vowels);
        }

        return max_num_vowels;
    }
};
