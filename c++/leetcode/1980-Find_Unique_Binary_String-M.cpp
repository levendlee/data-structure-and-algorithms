class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> hashset;
        auto to_int = [](const string& s) {
            int res = 0;
            for (char c : s) {
                res = res * 2 + (c - '0');
            }
            return res;
        };
        for (const string& s : nums) {
            hashset.insert(to_int(s));
        }
        auto to_str = [](int num, int n) {
            std::string s(n, '0');
            int bit = 0;
            while (num) {
                s[n - 1 - bit] += num & 0x1;
                num >>= 1;
                ++bit;
            }
            return s;
        };
        int n = nums[0].size();
        for (int i = 0; i < (1 << n); ++i) {
            if (!hashset.count(i)) {
                return to_str(i, n);
            }
        }
        return "";
    }
};

//

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        const int n = nums.size();
        string res;
        for (int i = 0; i < n; ++i) {
            res += nums[i][i] == '0' ? '1' : '0';
        }
        return res;
    }
};
