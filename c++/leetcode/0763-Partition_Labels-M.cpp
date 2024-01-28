class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last_seen[26];
        fill(last_seen, last_seen + 26, -1);

        for (int i = 0; i < s.size(); ++i) {
            last_seen[s[i] - 'a'] = i;
        }

        vector<int> partitions;
        int lbound = 0;
        int rbound = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || i > rbound) {
                partitions.push_back(rbound - lbound + 1);
                lbound = i;
                rbound = i;
            }
            if (i < s.size()) {
                rbound = max(rbound, last_seen[s[i] - 'a']);
            }
        }
        return partitions;

    }
};