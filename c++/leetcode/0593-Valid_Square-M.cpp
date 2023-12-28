// 593 Valid Square
// https://leetcode.com/problems/valid-square

// version: 1; create time: 2020-01-26 22:16:04;
class Solution {
public:
  bool isPerpendicular(const vector<int> &p0, const vector<int> &p1,
                       const vector<int> &p2) {
    return ((p0[0] - p1[0]) * (p1[0] - p2[0]) +
            (p0[1] - p1[1]) * (p1[1] - p2[1])) == 0;
  }

  int calcLen(const vector<int> &p0, const vector<int> &p1) {
    auto x = p0[0] - p1[0];
    auto y = p0[1] - p1[1];
    return x * x + y * y;
  }

  bool checkSquare(vector<int> &perm, vector<vector<int>> &points) {
    const auto vec = [&](const int i) -> vector<int> & {
      return points[perm[i]];
    };
    for (int i = 0; i < 4; ++i) {
      int j = (i + 1) % 4;
      int k = (j + 1) % 4;
      if (!isPerpendicular(vec(i), vec(j), vec(k))) {
        return false;
      }
      const int s1 = calcLen(vec(i), vec(j));
      const int s2 = calcLen(vec(j), vec(k));
      if (s1 != s2 || s1 == 0) {
        return false;
      }
    }
    return true;
  }

  bool checkPermutation(vector<int> &perm, vector<vector<int>> &points) {
    if (perm.size() == 4) {
      return checkSquare(perm, points);
    }
    for (int i = 0; i < 4; ++i) {
      if (std::find(perm.begin(), perm.end(), i) == perm.end()) {
        perm.push_back(i);
        if (checkPermutation(perm, points)) {
          return true;
        }
        perm.pop_back();
      }
    }
    return false;
  }

  bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3,
                   vector<int> &p4) {
    vector<vector<int>> points = {p1, p2, p3, p4};
    vector<int> perm;
    return checkPermutation(perm, points);
  }
};

//

class Solution {
public:
  bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3,
                   vector<int> &p4) {
    vector<vector<int>> points = {p1, p2, p3, p4};

    // Traverse indices in certain order to form edges of square.
    auto last_edge = [&](const vector<int> &indices) {
      int n = indices.size();
      int x = points[indices[n - 2]][0] - points[indices[n - 1]][0];
      int y = points[indices[n - 2]][1] - points[indices[n - 1]][1];
      return std::make_pair(x, y);
    };

    auto length2 = [](const pair<int, int> &xy) {
      auto [x, y] = xy;
      return x * x + y * y;
    };

    auto vertical = [](const pair<int, int> &xy1, const pair<int, int> &xy2) {
      auto [x1, y1] = xy1;
      auto [x2, y2] = xy2;
      return x1 * x2 + y1 * y2 == 0;
    };

    function<bool(vector<int> &)> dfs;
    dfs = [&](vector<int> &indices) {
      if (indices.size() == 4)
        return true;
      auto pre_edge =
          indices.size() >= 2 ? last_edge(indices) : std::make_pair(0, 0);
      for (int k = 0; k < 4; ++k) {
        if (std::find(indices.begin(), indices.end(), k) != indices.end())
          continue;
        indices.push_back(k);
        auto cur_edge = last_edge(indices);
        if (indices.size() == 2 || (length2(pre_edge) == length2(cur_edge)) &&
                                       vertical(pre_edge, cur_edge) &&
                                       length2(pre_edge) > 0) {
          if (dfs(indices)) {
            return true;
          }
        }
        indices.pop_back();
      }
      return false;
    };

    vector<int> indices = {0};
    return dfs(indices);
  }
};

//
