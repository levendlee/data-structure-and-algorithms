class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long base = pow(10, 9) + 7;
        long score1 = 0, score2 = 0;
        long new_score1 = 0, new_score2 = 0;
        int i = nums1.size() - 1;
        int j = nums2.size() - 1;
        while (i >= 0 || j >= 0) {
            int ni = i, nj = j;
            new_score1 = score1; new_score2 = score2;
            if (j < 0 || i >= 0 && nums1[i] > nums2[j]) {
                new_score1 = nums1[i] + score1;
                ni--;
            }
            else if (i < 0 || j >= 0 && nums1[i] < nums2[j]) {
                new_score2 = nums2[j] + score2;
                nj--;
            }
            else {
                new_score1 = nums1[i] + max(score1, score2);
                new_score2 = nums2[j] + max(score1, score2);
                ni--;
                nj--;
            }
            score1 = new_score1;
            score2 = new_score2;
            i = ni; j = nj;
        }
        return max(score1, score2) % base;
    }
};
