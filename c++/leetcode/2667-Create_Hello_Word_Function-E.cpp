#include <string>
#include <iostream>

struct HelloWord {
  template<typename... Args>
  std::string operator()(Args... args) {
    return "Hello Word!";
  }
};

HelloWord CreateHelloWord() {
  return HelloWord();
}

int main() {
  auto f = CreateHelloWord();
  std::cout << f('a', 1, 2.0) << "\n";
  std::cout << f(1, 2, 3, 4, 5, 6) << "\n";
}
