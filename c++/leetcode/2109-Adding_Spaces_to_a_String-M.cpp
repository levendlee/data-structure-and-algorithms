class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res(s.size() + spaces.size(), ' ');
        int loc = 0;
        int j = 0;
        for (int i : spaces) {
            copy(s.begin() + loc, s.begin() + i, res.begin() + j);
            j += i - loc + 1;
            loc = i;
        }
        copy(s.begin() + loc, s.end(), res.begin() + j);
        return res;
    }
};