class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        int n1 = arr1.size(), n2 = arr2.size();
        int i = n1 - 1, j = n2 - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int lhs = i >= 0 ? arr1[i] : 0;
            int rhs = j >= 0 ? arr2[j] : 0;
            int sum = lhs + rhs + carry;
            if (sum < 0) {
                sum += 2;
                carry = 1;
            } else {
                carry = -(sum >> 1);
            }
            res.push_back(sum & 0x1);
            --i;
            --j;
        }
        while (res.size() > 1 && res.back() == 0) res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};