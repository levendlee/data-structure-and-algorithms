#include "common.hpp"

struct Object {
    int color;
    int cata;
};

vector<vector<int>> PairObjects(const vector<Object>& objects) {
    const int n = objects.size();

    vector<vector<int>> pairs;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int score = (objects[i].color != objects[j].color) + \
                        (objects[i].cata != objects[j].cata);
            pairs.push_back({-score, i, j});
        }
    }

    sort(pairs.begin(), pairs.end());

    vector<vector<int>> res;
    vector<bool> paired(n, false);
    for (auto& p : pairs) {
        if (paired[p[1]] || paired[p[2]]) continue;
        paired[p[1]] = true;
        paired[p[2]] = true;
        res.push_back({p[1], p[2]});
    }

    return res;
}

int main() {
    vector<Object> objects = {{0, 1}, {1, 3}, {1, 3}, {1, 2}, {0, 2}, {1, 5}};
    auto res = PairObjects(objects);
    for (auto& p : res) cout << p[0] << "," << p[1] << "; ";
    cout << "\n";
    return 0;
}