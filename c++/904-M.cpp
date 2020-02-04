class Solution {
public:
    int totalFruit(vector<int>& tree) {
        const int n = tree.size();
        int i = 0, j = 0;
        int k0 = -1, k1 = -1, cnt0 = 0, cnt1 = 1;
        int total = 0;
        while (j < n) {
            const auto k = tree[j];
            cnt0 += k0 == k;
            cnt1 += k1 == k;
            if (k0 == -1 && k1 != k) {
                k0 = k; cnt0 = 1;
            } else if (k0 != k && k1 == -1) {
                k1 = k; cnt1 = 1;
            } else if (k0 != k && k1 != k) {
                while (i < j) {
                    cnt0 -= tree[i] == k0;
                    cnt1 -= tree[i] == k1;
                    ++i;
                    if (cnt0 == 0) {
                        k0 = -1; break;
                    } else if (cnt1 == 0) {
                        k1 = -1; break;
                    }
                }
                continue;
            }
            total = std::max(total, j - i + 1);
            ++j;
        }
        return total;
    }
};