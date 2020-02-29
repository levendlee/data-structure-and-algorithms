// 844 Backspace String Compare
// https://leetcode.com/problems/backspace-string-compare

// version: 1; create time: 2019-10-26 16:29:05;
class Solution {
public:
    void toStack(std::stack<char>& ss, std::string& S) {
      for ( auto c : S ) {
        if ( c != '#' ) {
          ss.push(c);
        } else {
          if (!ss.empty()) {
            ss.pop();
          }
        }
      }
    }

    bool backspaceCompare(string S, string T) {
      std::stack<char> ss, ts;
      toStack( ss, S );
      toStack( ts, T );
      while ( !ss.empty() && !ts.empty() ) {
        if ( ss.top() != ts.top() ) {
          return false;
        }
        ss.pop(); ts.pop();
      }
      return ss.empty() && ts.empty();
    }
};
