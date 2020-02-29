// 957 Prison Cells After N Days
// https://leetcode.com/problems/prison-cells-after-n-days

// version: 1; create time: 2019-12-30 11:34:15;
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        constexpr int size = 8;

        bitset<size> data;
        for (int i = 0; i < size; ++i) {
            data[i] = cells[i];
        }

        bool tail = false;
        bitset<size> tmp;
        unordered_map<bitset<size>, int> mem;
        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < size; ++i) {
                tmp[i] = (i > 0) && (i < size - 1) && (data[i-1] == data[i+1]);
            }
            std::swap(data, tmp);
            if (!tail) {
                if (mem.count(data)) {
                    tail = true;
                    int period = k - mem[data];
                    k += ((N - k) / period - 1) * period;
                } else {
                    mem[data] = k;
                }
            }
        }

        vector<int> output(size);
        for (int i = 0; i < size; ++i) {
            output[i] = data[i];
        }
        return output;
    }
