// 1352 Product of the Last K Numbers
// https://leetcode.com/problems/product-of-the-last-k-numbers

// version: 1; create time: 2020-02-29 22:27:35;
class ProductOfNumbers {
private:
    vector<long> products;
    vector<int> zeros;

public:
    ProductOfNumbers() {
        products.push_back(1);
        zeros.push_back(0);
    }

    void add(int num) {
        {
        auto pre = products.empty() ? 1 : products.back();
        products.push_back(num != 0 ? (pre * num) : 1);
        }
        {
        auto pre = zeros.empty() ? 0 : zeros.back();
        zeros.push_back(num == 0 ? (pre + 1) : pre);
        }
    }

    int getProduct(int k) {
        const int n = products.size();
        int i = n - k - 1, j = n - 1;
        if (zeros[i] != zeros[j]) return 0;
        else return products[j] / products[i];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
