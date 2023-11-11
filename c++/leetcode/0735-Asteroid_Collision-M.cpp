class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int n : asteroids) {
            int num = n;
            while (!res.empty() && res.back() > 0 && num < 0) {
                int top = res.back();
                res.pop_back();
                if (abs(top) > abs(num)) {
                    num = top;
                } else if (abs(top) == abs(num)) {
                    num = 0;
                    break;
                }
            }
            if (num) res.push_back(num);
        }
        return res;
    }
};
