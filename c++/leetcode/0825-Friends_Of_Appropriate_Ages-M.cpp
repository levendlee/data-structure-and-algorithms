// 825 Friends Of Appropriate Ages
// https://leetcode.com/problems/friends-of-appropriate-ages

// version: 1; create time: 2020-02-07 22:24:42;
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

//

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int requests = 0;
        for (int x : ages) {
            int min_y = x / 2 + 7;
            auto i = upper_bound(ages.begin(), ages.end(), min_y);
            auto j = upper_bound(ages.begin(), ages.end(), x);
            requests += max(int(j - i - 1), 0);
        }
        return requests;
    }
};
