#include <string>
#include <vector>
#include <map>
#include <iostream>

int compress(std::string& chars) {
    const int n = chars.size();

    int r = 0;
    int w = 0;
    int cnt = 0;
    char c;
    while (r <= n) {
        if (r == 0 || r < n && c == chars[r]) {
            ++cnt;
        } else {
            chars[w++] = c;
            if (cnt != 1) {
                for (char d : std::to_string(cnt)) {
                    chars[w++] = d;
                }
            }
            cnt = 1;
        }
        if (r == n) break;
        c = chars[r++];
    }
    return w;
}

std::string compressPackets(std::vector<std::string>& packets) {
    int m = packets.size();

    std::string compressed;
    char c;
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
      int n = packets[i].size();
      for (int j = 0; j < n; ++j) {
        if (i == 0 && j == 0 || c == packets[i][j]) {
          ++cnt;
        } else {
          compressed += c;
          if (cnt > 1) {
            compressed += std::to_string(cnt);
          }
          cnt = 1;
        }
        c = packets[i][j];
      }
    }
    
    compressed += c;
    if (cnt > 1) {
      compressed += std::to_string(cnt);
    }
    return compressed;
}

std::string compressUnorderedPackets(std::vector<std::string>& packets) {
    int m = packets.size();

    std::map<char, int> counters;
    for (int i = 0; i < m; ++i) {
      for (char c : packets[i]) {
        ++counters[c];
      }
    }
    
    std::string compressed;
    for (const auto& [c, cnt] : counters) {
      compressed += c;
      if (cnt > 1) {
        compressed += std::to_string(cnt);
      }
    }
    return compressed;
}

int main() {
  std::string s = "abbccccdddddddd";
  int size = compress(s);
  s.resize(size);
  std::cout << s << "\n";

  std::vector<std::string> ss = {"abbc", "cccdd", "dddddd"};
  auto compressed = compressPackets(ss);
  std::cout << compressed << "\n";
  
  ss = {"cccdd", "abbc", "dddddd"};
  compressed = compressUnorderedPackets(ss);
  std::cout << compressed << "\n";

}
