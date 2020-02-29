// 846 Hand of Straights
// https://leetcode.com/problems/hand-of-straights

// version: 1; create time: 2019-12-10 20:01:19;
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        const int n = hand.size();
        if (n % W) {
            return false;
        }

        std::sort(hand.begin(), hand.end());
        std::deque<int> groups;
        int sums = 0;
        for (int i = 0; i < n; ++i) {
            int j = i;
            while (i + 1 < n && hand[i+1] == hand[i]) {
                ++i;
            }
            int l = i - j + 1;

            if ((j != 0) && (sums != 0) && (hand[j] != hand[j-1] + 1)) {
                return false;
            }
            if (l < sums) {
                return false;
            }

            groups.push_back(l - sums);
            sums += l - sums;

            if (groups.size() >= W) {
                sums -= groups.front();
                groups.pop_front();
            }
        }

        while (!groups.empty() && groups.front() == 0) {
            groups.pop_front();
        }
        return groups.empty();
    }
};
