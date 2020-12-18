class Solution {
public:
    int minimumDeletions(string s) {
        const int n = s.size();
        if (n == 0) return 0;
        
        vector<int> a_count(n);
        a_count[0] = s[0] == 'a';
        for (int i = 1; i < n; ++i) {
            a_count[i] = a_count[i-1] + (s[i] == 'a');
        }
        
        int min_delete = a_count[n-1];
        for (int i = 0; i < n; ++i) {
            int num_b_delete = i + 1 - a_count[i];
            int num_a_delete = a_count[n-1] - a_count[i];
            min_delete = std::min(min_delete, (num_a_delete + num_b_delete));
        }
        return min_delete;
    }
};
