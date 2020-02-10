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