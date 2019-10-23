class Solution {
public:
    string getHint(string secret, string guess) {
        int digits1[10]{};
        int digits2[10]{};

        const int n = secret.size();

        int match1 = 0;
        for (int i = 0; i < n; ++i) {
           if (secret[i] == guess[i]) match1++;
           ++digits1[secret[i] - '0'];
           ++digits2[guess[i] - '0'];
        }

        int match2 = 0;
        for (int i = 0; i < 10; ++i) {
           match2 += std::min(digits1[i], digits2[i]);
        }

        return to_string(match1) + "A" + to_string(match2 - match1) + "B";
    }
};