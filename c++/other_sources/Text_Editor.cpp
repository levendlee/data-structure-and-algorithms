#include <iomanip>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::unordered_map<int, int>
FindMatchingBraces(const std::vector<std::string> &code) {
  std::cerr << "FindMatchingBraces called!\n";
  std::unordered_map<int, int> braces;
  std::stack<int> stk;
  const int n = code.size();
  for (int i = 0; i < n; ++i) {
    const auto &line = code[i];
    // std::cerr << line << "\n";
    if (line.empty())
      continue;
    if (line.back() == '{') {
      // std::cerr << "Pushing " << i << "\n";
      stk.push(i);
    } else if (line.back() == '}') {
      // std::cerr << "Popping " << stk.top() << "\n";
      braces[stk.top()] = i;
      stk.pop();
    }
  }
  return braces;
}

void PrintToScreen(const std::vector<std::string> &code) {
  for (int i = 0; i < code.size(); ++i) {
    std::cout << std::setfill('0') << std::setw(2) << i;
    std::cout << code[i] << "\n";
  }
}

class Editor {
public:
  Editor(const std::vector<std::string> &code)
      : code_(code), braces_(FindMatchingBraces(code)) {
    const int n = code.size();
    for (int i = 0; i < n; ++i) {
      line_mapping_[i] = i;
    }
    PrintToScreen(Display());
    std::cerr << "Editor initialized!\n";
  }

  void ToggleAndDisplay(int display_line) {
    std::cerr << "ToggleAndDisplay at " << display_line << "\n";
    Toggle(display_line);
    PrintToScreen(Display());
    std::cerr << "\n\n";
  }

private:
  bool IsFolded(int original_line) { return folded_.count(original_line); }

  void Toggle(int display_line) {
    int original_line = line_mapping_[display_line];
    if (IsFolded(original_line)) {
      folded_.erase(original_line);
    } else {
      folded_.insert(original_line);
    }
  }

  std::vector<std::string> Display() {
    std::vector<std::string> stream;
    int display_line = 0;
    int original_line = 0;
    do {
      line_mapping_[display_line++] = original_line;
      auto iter = braces_.find(original_line);
      if (iter == braces_.end()) {
        stream.push_back("  " + code_[original_line]);
        ++original_line;
      } else {
        if (IsFolded(original_line)) {
          stream.push_back("+ " + code_[original_line] + "...}");
          original_line = iter->second + 1;
        } else {
          stream.push_back("- " + code_[original_line]);
          ++original_line;
        }
      }
    } while (original_line < code_.size());
    return stream;
  }

  const std::vector<std::string> code_;
  std::unordered_set<int> folded_;
  std::unordered_map<int, int> braces_;
  std::unordered_map<int, int> line_mapping_;
};

int main() {
  std::vector<std::string> code = {
      "int NestedFunction(std::vector<int>& arr) {", // 0
      "   int sum = 0;",                             // 1
      "   for (int i = 0; i < 10; ++i) {",           // 2
      "       for (int j = 0; j < 10; ++j) {",       // 3
      "           for (int k = 0; k < 10; ++k) {",   // 4
      "               sum += i + j + k;",            // 5
      "           }",                                // 6
      "       }",                                    // 7
      "   }",                                        // 8
      "   for (int i = 0; i < 10; ++i) {",           // 9
      "       for (int j = 0; j < 10; ++j) {",       // 10
      "           for (int k = 0; k < 10; ++k) {",   // 11
      "               sum += i + j + k;",            // 12
      "           }",                                // 13
      "       }",                                    // 14
      "   }",                                        // 15
      "}"                                            // 16
  };

  Editor editor(code);

  editor.ToggleAndDisplay(1);
  editor.ToggleAndDisplay(1);

  editor.ToggleAndDisplay(4);
  editor.ToggleAndDisplay(3);
  editor.ToggleAndDisplay(2);

  editor.ToggleAndDisplay(2);
  editor.ToggleAndDisplay(3);
  editor.ToggleAndDisplay(4);

  editor.ToggleAndDisplay(4);
  editor.ToggleAndDisplay(9);

  return 0;
}