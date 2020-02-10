struct Frac {
    int idx;
    int numerator;
    int denominator;
    double val;

    Frac(int idx, int num, int den) : idx(idx), numerator(num), denominator(den) {
        val = 1.0 * num / den;
    }
    bool operator<(const Frac& other) const {
        return val > other.val;
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        const int n = A.size();
        priority_queue<Frac> pq;

        for (int i = 1; i < n; ++i) {
            pq.emplace(0, A[0], A[i]);
        }

        int cnt = 0;
        while (true) {
            auto frac = pq.top(); pq.pop();
            ++cnt;
            if (cnt == K) {
                return {frac.numerator, frac.denominator};
            }
            auto idx = frac.idx;
            if (idx + 1 < n) {
                pq.emplace(idx + 1, A[idx + 1], frac.denominator);
            }
        }
        return {};
    }
};