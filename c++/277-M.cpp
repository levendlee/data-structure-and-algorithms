// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        /*
        vector<int> ppl(n, 0);
        std::iota(ppl.begin(), ppl.end(), 0);

        while (ppl.size() != 1) {
            vector<int> nppl;
            for (int i = 0; i + 1 < ppl.size(); i += 2) {
                if (knows(ppl[i], ppl[i+1])) {
                    nppl.push_back(ppl[i+1]);
                } else {
                    nppl.push_back(ppl[i]);
                }
            }
            if (ppl.size() % 2) {
                nppl.push_back(ppl.back());
            }
            ppl = std::move(nppl);
        }

        int candidate = ppl[0];
        */
        int candidate = 0;
        for (int i = 1; i < n; ++i) {
            if (knows(candidate, i))
                candidate = i;
        }
        for (int i = 0; i < n; ++i) {
            if (candidate == i) continue;
            if (!knows(i, candidate) || knows(candidate, i)) return -1;
        }
        return candidate;
    }
};