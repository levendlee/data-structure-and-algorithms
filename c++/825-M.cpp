class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int age_cnt[120] = {0};
        for (const auto& a : ages) {
            ++age_cnt[a - 1];
        }
        int requests = 0;
        for (int b = 1; b <= 120; ++b) {
            for (int a = b; a <= 120; ++a) {
                if (b <= 0.5 * a + 7 || b > 100 && a < 100) continue;
                requests += a == b ? age_cnt[a-1] * (age_cnt[a-1] - 1) :
                                     age_cnt[a-1] * age_cnt[b-1];
            }
        }
        return requests;
    }
};