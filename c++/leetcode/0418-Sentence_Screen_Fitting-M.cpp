class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int times = 0;
        int i = 0, n = sentence.size();
        vector<int> times_mem = {0};
        for (int r = 0; r < rows; ++r) {
            int buffer = 0;
            while (buffer + sentence[i].size() <= cols) {
                buffer += sentence[i].size() + 1;
                ++i;
                if (i == n) {
                    ++times;
                    i = 0;
                }
            }
            times_mem.push_back(times);
            if (i == 0) {
                times *= rows / (r + 1);
                times += times_mem[rows - (rows / (r + 1)) * (r + 1)];
                break;
            }
        }
        return times;
    }
};
