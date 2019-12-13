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