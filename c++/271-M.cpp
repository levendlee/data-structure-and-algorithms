class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const auto& s: strs) {
            encoded.push_back('$');
            for (const auto& c: s) {
                encoded.push_back(c);
                if (c == '#' || c == '$') {
                    encoded.push_back(c);
                }
            }
            encoded.push_back('#');
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;

        const int n = s.size();
        string cur_s;
        for (int i = 0; i < n; ++i) {
            if (s[i] != '#' && s[i] != '$') {
                cur_s.push_back(s[i]);
            } else {
                if ((i + 1 < n) && (s[i+1] == s[i])) {
                    cur_s.push_back(s[i]);
                    ++i;
                } else if (s[i] == '$') {
                    //cur_s = "";
                } else {
                    decoded.push_back(cur_s);
                    cur_s = "";
                }
            }
        }

        return decoded;
    }
};