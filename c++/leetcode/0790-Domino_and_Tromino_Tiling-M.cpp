class Solution {
public:
    int numTilings(int n) {
        constexpr int modulo = 1e9 + 7;

        if (n == 1) return 1;
        if (n == 2) return 2;
        
        // Number of tilings without a gap in last two steps.
        long long gap0_0 = 1, gap0_1 = 2;
        // Number of tilings with a gap in last two steps.
        long long gap1_1 = 1;
        for (int i = 3; i <= n; ++i) {
            // gap0_1: filing with 1 vertical
            // gap0_0: filing with 2 horizontals
            // gap1_1: filing with 1 tri or 1 horizontal
            long long  ngap0_1 = (gap0_0 + gap0_1 + 2 * gap1_1) % modulo;
            long long  ngap1_1 = gap0_0 + gap1_1;
            gap0_0 = gap0_1;
            gap0_1 = ngap0_1;
            gap1_1 = ngap1_1;
        }

        return gap0_1;
    }
};
