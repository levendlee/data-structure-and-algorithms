#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

int BruceForce(const std::vector<int> &tasks) {
  std::queue<int> q;
  for (int t : tasks) {
    q.push(t);
  }
  int total_time = 0;
  int timestamp = 0;
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    ++timestamp;
    if (!--t) {
      total_time += timestamp;
    } else {
      q.push(t);
    }
  }
  return total_time;
}

// Buggy
int SortAndCalc(const std::vector<int> &tasks) {
  std::vector<std::pair<int, int>> value2index;
  const int n = tasks.size();
  for (int i = 0; i < n; ++i) {
    value2index.push_back({tasks[i], i});
  }
  std::sort(value2index.begin(), value2index.end());

  int total_time = 0;
  // Number of elements has value equal or larger than current value.
  int greater_equal_count = n;
  // Accumulative number of elements has value equal to current value.
  int equal_count = 0;
  int running_time = 0;
  int prev2_value = 0;
  int prev1_value = value2index[0].first;

  std::set<int> indices;
  for (auto [v, i] : value2index) {
    if (v != prev1_value) {
      running_time += greater_equal_count * (prev1_value - prev2_value);
      prev2_value = prev1_value;

      greater_equal_count -= equal_count;
      equal_count = 0;
    }
    ++equal_count;

    auto iter = indices.insert(i).first;
    int smaller_before_count = std::distance(indices.begin(), iter);
    int t = running_time + i + 1 - smaller_before_count;
    std::cerr << "For i=" << i << ", v=" << v << ": time=" << t << "\n";
    total_time += t;
    prev1_value = v;
  }
  return total_time;
}

int main() {
  std::vector<std::vector<int>> testcases = {{3, 1, 2}, {3, 1, 5, 9}};
  for (const auto& tc : testcases) {
    std::cout << BruceForce(tc)  << " v.s. " << SortAndCalc(tc) << "\n";
  }

  return 0;
}
