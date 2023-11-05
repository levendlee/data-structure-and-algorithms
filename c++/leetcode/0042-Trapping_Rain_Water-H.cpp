// T: O(N). S: O(N)
class Solution {
public:
int trap(vector<int>& height) {
        const int n = height.size();

        vector<int> r_highest_vec(n, 0);
        int r_highest = 0;
        for (int i = n - 1; i >= 0; --i) {
            r_highest = max(r_highest, height[i]);
            r_highest_vec[i] = r_highest;
        }

        int trapped = 0;
        int l_highest = 0;
        for (int i = 0; i < n; ++i) {
            l_highest = max(l_highest, height[i]);
            trapped += max(min(l_highest, r_highest_vec[i]) - height[i], 0);
        }

        return trapped;
    }
};

// T: O(N). S: O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        int highest_idx = max_element(height.begin(), height.end()) - height.begin();
        int trapped = 0;
        int cur_highest = 0;
        
        for (int i = 0; i < highest_idx; ++i) {
            cur_highest = max(cur_highest, height[i]);
            trapped += cur_highest - height[i];
        }

        cur_highest = 0;
        for (int i = n - 1; i > highest_idx; --i) {
            cur_highest = max(cur_highest, height[i]);
            trapped += cur_highest - height[i];
        }

        return trapped;
    }
};
