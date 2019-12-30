// TODO: Using Tuple is Really low efficiency. Consider using string concatenation.
using Record = tuple<string, string, string>;

namespace std {
    template<>
    struct hash<Record>{
        size_t operator()(const Record& record) const {
            auto hasher = hash<string>();
            return hasher(get<0>(record)) ^ hasher(get<1>(record)) ^ hasher(get<2>(record));
        }
    };
}

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, unordered_set<Record>> users;
        unordered_map<Record, unordered_set<string>> counters;

        const int n = timestamp.size();
        vector<short> ranks(n);
        std::iota(ranks.begin(), ranks.end(), 0);
        std::sort(ranks.begin(), ranks.end(),
                 [&](const auto lhs, const auto rhs) { return timestamp[lhs] < timestamp[rhs]; });

        const auto process_record = [&](const string& username, const string& web0, const string& web1, const string& web2) {
            const auto record = std::make_tuple(web0, web1, web2);
            users[username].insert(record);
            if (!web0.empty()) {
                counters[record].insert(username);
            }
        };

        for (const auto& i : ranks) {
            auto records = users[username[i]];
            records.insert(Record());
            for (const auto& record : records) {
                process_record(username[i], std::get<1>(record), std::get<2>(record), website[i]);
                process_record(username[i], std::get<0>(record), std::get<2>(record), website[i]);
                process_record(username[i], std::get<0>(record), std::get<1>(record), website[i]);
            }
        }

        Record common_record;
        int visit_users = 0;
        for (const auto& p : counters) {
            const auto& record = p.first;
            const auto& visit = p.second.size();
            if ((visit > visit_users) || (visit == visit_users) && (record < common_record)) {
                common_record = record;
                visit_users = visit;
            }
        }

        return {std::get<0>(common_record), std::get<1>(common_record), std::get<2>(common_record)};
    }
};