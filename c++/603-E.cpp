class StringIterator {
private:
    std::vector<std::pair<char, int>> buff_;

    int getNumber(const string& str, int& idx) {
        int start = idx;
        while (idx < str.size() && isdigit(str[idx])) {
            ++idx;
        }
        return std::stoi(str.substr(start, idx - start));
    }

public:
    StringIterator(string s) {
        const int n = s.size();
        int idx = 0;
        while (idx < n) {
            const char c = s[idx++];
            const int num = getNumber(s, idx);
            buff_.emplace_back(c, num);
        }
        std::reverse(buff_.begin(), buff_.end());
    }

    char next() {
        if (hasNext()) {
            const char c = buff_.back().first;
            --buff_.back().second;
            if (buff_.back().second == 0) {
                buff_.pop_back();
            }
            return c;
        } else {
            return ' ';
        }
    }

    bool hasNext() {
        return !buff_.empty();
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */