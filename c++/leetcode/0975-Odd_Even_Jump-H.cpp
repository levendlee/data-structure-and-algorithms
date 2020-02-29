// 975 Odd Even Jump
// https://leetcode.com/problems/odd-even-jump

// version: 1; create time: 2020-02-02 21:15:27;
class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        const int n = A.size();
        vector<bool> odd(n, false);
        odd[n-1] = true;
        vector<bool> even(n, false);
        even[n-1] = true;

        set<pair<int, int>> bst;
        for (int i = n - 1; i >= 0; --i) {
            auto iter = bst.lower_bound({A[i], -1});
            if (iter != bst.end()) {
                odd[i] = even[iter->second];
            }
            if (iter != bst.end() && iter->first == A[i]) {
                even[i] = odd[iter->second];
            } else if (iter != bst.begin()) {
                auto target = (--iter)->first;
                auto idx = bst.lower_bound({target, -1})->second;
                even[i] = odd[idx];
            }
            bst.insert({A[i], i});
        }

        int cnt = 0;
        for (const auto o : odd) {
            cnt += o;
        }
        return cnt;
    }
};
