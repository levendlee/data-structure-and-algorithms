class Solution {
public:
    bool isLetterLog(const string& str) {
        int idx = str.find(' ');
        return isalpha(str[idx + 1]);
    }

    bool compareLetterLog(const string& lhs, const string& rhs) {
        const int idx0 = lhs.find(' ');
        const int idx1 = rhs.find(' ');
        const auto t0 = lhs.substr(idx0 + 1);
        const auto t1 = rhs.substr(idx1 + 1);
        if (t0 < t1) return true;
        if (t0 > t1) return false;
        const auto i0 = lhs.substr(0, idx0);
        const auto i1 = rhs.substr(0, idx1);
        return i0 < i1;
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        unordered_map<string, int> indices;
        const int n = logs.size();
        for (int i = 0; i < n; ++i) {
            indices[logs[i]] = i;
        }

        const auto comp = [&](const auto& lhs, const auto& rhs) {
            bool l0 = isLetterLog(lhs);
            bool l1 = isLetterLog(rhs);
            if (!l0 && !l1) return indices[lhs] < indices[rhs]; // Both digit, original order
            if (l0 && !l1) return true;  // Letter log comes first
            if (!l0 && l1) return false; // ...
            return compareLetterLog(lhs, rhs);
        };

        std::sort(logs.begin(), logs.end(), comp);
        return logs;
    }
};