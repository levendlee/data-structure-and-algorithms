class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int plant = 0, not_plant = 0, new_plant, new_not_plant;
        for (int f : flowerbed) {
            if (f) {
                new_plant = not_plant;
                new_not_plant = INT_MIN;
            } else {
                new_plant = not_plant + 1;
                new_not_plant = max(plant, not_plant);
            }
            plant = new_plant;
            not_plant = new_not_plant;
        }
        if (plant >= n || not_plant >= n) {
            return true;
        }

        return false;
    }
};
