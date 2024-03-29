// 670 Maximum Swap
// https://leetcode.com/problems/maximum-swap

// version: 1; create time: 2020-02-08 14:50:16;
class Solution {
public:
    int maximumSwap(int num) {
        auto str = to_string(num);
        /*
        auto max_str = str;

        const int n = str.size();
        for (int i = n - 2; i >= 0; --i) {
            max_str[i] = std::max(max_str[i+1], max_str[i]);
        }

        int swap1 = 0, swap2 = 0;
        int i = 0;
        while (i < n) {
            if (max_str[i] != str[i]) {
                swap1 = i; swap2 = i;
                break;
            }
            ++i;
        }
        while (i < n) {
            if (str[swap2] <= str[i]) {
                swap2 = i;
            }
            ++i;
        }
        std::swap(str[swap1], str[swap2]);
        return stoi(str);
        */
        const int n = str.size();
        int last[10] = {-1};
        for (int i = 0; i < n; ++i) {
            last[str[i] - '0'] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int d = 9; d > str[i] - '0'; --d) {
                if (last[d] > i) {
                    std::swap(str[last[d]], str[i]);
                    goto result;
                }
            }
        }
        result:
        return stoi(str);
    }
};

//

class Solution {
public:
    int maximumSwap(int num) {
        string num_str = to_string(num);
        const int n = num_str.size();

        vector<char> highest_bit(n);
        char c = '0';
        for (int i = n - 1; i >= 0; --i) {
            c = max(c, num_str[i]);
            highest_bit[i] = c;
        }

        int i = 0;
        while (i < n) {
            if (highest_bit[i] != num_str[i]) break;
            ++i;
        }
        if (i == n) return num;

        int j = n - 1;
        while (j >= 0) {
            if (highest_bit[i] == num_str[j]) break;
            --j;
        }

        swap(num_str[i], num_str[j]);
        return stoi(num_str);
    }
};
