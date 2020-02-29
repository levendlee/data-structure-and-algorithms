// 605 Can Place Flowers
// https://leetcode.com/problems/can-place-flowers

// version: 1; create time: 2020-02-09 20:53:36;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        const int m = flowerbed.size();
        for (int i = 0; i < m; ++i) {
            //std::cout << i << "\n";
            if ((i == 0 || flowerbed[i-1] == 0) && (flowerbed[i] == 0) && (i == m - 1 || flowerbed[i+1] == 0)) {
                flowerbed[i] = 1;
                ++cnt;
            }
            //std::cout << "OK\n";
        }
        return cnt >= n;
    }
};
