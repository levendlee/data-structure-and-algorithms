class Solution {
public:
/*
    bool possiblyEquals(string s1, string s2) {
        const int n1 = s1.size(), n2 = s2.size();
        int i = 0, j = 0, buffer1 = 0, buffer2 = 0;
        while (i < n1 || j < n2) {
            // Consumes all leading digits.
            int ii = i;
            while (ii < n1 && isdigit(s1[ii])) ++ii;
            if (ii != i) {
                buffer1 += stoi(s1.substr(i, ii - i));
                i = ii;
            }
            int jj = j;
            while (jj < n2 && isdigit(s2[jj])) ++jj;
            if (jj != j) {
                buffer2 += stoi(s2.substr(j, jj - j));
                j = jj;
            }
            // No leading digists left. End of string or chars.
            if (buffer1 && buffer2) {
                int step = min(buffer1, buffer2);
                buffer1 -= step;
                buffer2 -= step;
            } else if (buffer1) {
                --buffer1;
                if (j == n2) return false;
                ++j;
            } else if (buffer2) {
                --buffer2;
                if (i == n1) return false;
                ++i;
            } else {
                if (i == n1 || j == n2 || s1[i] != s2[j]) return false;
                ++i;
                ++j;
            }
        }
        // if s1 and s2 doesn't has same amount to be matched, then fail.
        return buffer1 != buffer2;
    }
*/

    bool possiblyEquals(string s1, string s2) {
        const int n1 = s1.size(), n2 = s2.size();

        function<bool(const int, const int, const int, const int)> dfs, dfs_mem;
        
        dfs = [&](const int i, const int buffer1, const int j, const int buffer2) {
            if (i == n1 && j == n2) {
                return buffer1 == buffer2;
            }
            if (buffer1 < 0 || buffer2 < 0) {
                return false;
            }
            // Consumes leading integers.
            if (i < n1 && isdigit(s1[i])) {
                int k = 0;
                while (i + k < n1 && isdigit(s1[i + k])) {
                    int num = stoi(s1.substr(i, ++k));
                    if (dfs_mem(i + k, buffer1 + num, j, buffer2)) {
                        return true;
                    }
                }
                return false;
            }
            else if (j < n2 && isdigit(s2[j])) {
                int k = 0;
                while (j + k < n2 && isdigit(s2[j + k])) {
                    int num = stoi(s2.substr(j, ++k));
                    if (dfs_mem(i, buffer1, j + k, buffer2 + num)) {
                        return true;
                    }
                }
                return false;
            }
           // No leading integers. End of string or chars.
            else if (buffer1 && buffer2) {
                int step = min(buffer1, buffer2);
                return dfs_mem(i, buffer1 - step, j, buffer2 - step);
            }
            else if (buffer1) {
                if (j == n2) return false;
                return dfs_mem(i, buffer1 - 1, j + 1, buffer2);
            }
            else if (buffer2) {
                if (i == n1) return false;
                return dfs_mem(i + 1, buffer1, j, buffer2 - 1);
            } else {
                return (s1[i] == s2[j]) && dfs_mem(i + 1, 0, j + 1, 0);
            }
        };

        struct Key {
            int i;
            int b1;
            int j;
            int b2;

            bool operator==(const Key& k) const {
                return k.i == i && k.b1 == b1 && k.j == j && k.b2 == b2;
            }
        };
        
        struct KeyHash {
            size_t operator()(const Key& k) const {
                return k.i ^ k.b1 ^ k.j ^ k.b2;
            }
        };

        unordered_map<Key, bool, KeyHash> mem;
        dfs_mem = [&](const int i, const int buffer1, const int j, const int buffer2) {
            Key key = {i, buffer1, j, buffer2};
            auto iter = mem.find(key);
            if (iter != mem.end()) {
                return iter->second;
            }
            bool res = dfs(i, buffer1, j, buffer2);
            mem[key] = res;
            return res;
        };

        return dfs_mem(0, 0, 0, 0);
    }
};
