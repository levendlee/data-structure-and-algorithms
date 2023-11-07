class Solution {
public:
    int compress(vector<char>& chars) {
        const int n = chars.size();

        int w = 0; // write index
        int r = 0; // read index
        while (r < n) {
            int start = r;
            char c = chars[r++];
            while (r < n && chars[r] == c) ++r;
            int d = r - start;
            chars[w++] = c;
            if (d == 1) continue;
            string s = to_string(d);
            for (char c : s) {
                chars[w++] = c;
            }
        }

        return w;
    }
};
