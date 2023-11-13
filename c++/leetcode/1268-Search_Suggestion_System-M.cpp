class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> results;

        sort(products.begin(), products.end());

        const int m = products.size();
        const int n = searchWord.size();
        for (int i = 1; i <= n; ++i) {
            string prefix = searchWord.substr(0, i);

            int lo = 0, hi = m - 1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (products[mid] < prefix) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }

            vector<string> cur_result;
            int k = lo;
            while (cur_result.size() < 3 && k < m && products[k].size() >= i && products[k].substr(0, i) == prefix) {
                cur_result.push_back(products[k++]);
            }
            results.emplace_back(move(cur_result));
        }

        return results;
    }
};
