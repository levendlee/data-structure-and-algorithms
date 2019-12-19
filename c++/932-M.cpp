class Solution {
public:

    vector<int> beautifulArray(int N) {
        vector<int> res = {1};
        while (res.size() < N) {
            vector<int> tmp;
            for (int i : res) {
                if (2 * i - 1 <= N) {
                    tmp.push_back(2 * i - 1);
                }
            }
            for (int i : res) {
                if (2 * i <= N)  {
                    tmp.push_back(2 * i);
                }
            }
            res = std::move(tmp);
        }
        return res;
    }
};