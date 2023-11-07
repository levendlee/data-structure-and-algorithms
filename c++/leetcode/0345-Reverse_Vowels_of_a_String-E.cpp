class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        const int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < j && !vowels.count(s[i])) ++i;
            while (i < j && !vowels.count(s[j])) --j;
            if (i < j) swap(s[i++], s[j--]);
        }
        return s;
    }
};
