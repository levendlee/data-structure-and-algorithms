class Solution {
public:
    string reformatDate(string date) {
        const unordered_map<string, int> months = {{"Jan", 1}, {"Feb", 2}, {"Mar", 3},
                                                   {"Apr", 4}, {"May", 5}, {"Jun", 6},
                                                   {"Jul", 7}, {"Aug", 8}, {"Sep", 9},
                                                   {"Oct", 10}, {"Nov", 11}, {"Dec", 12}};
        const int n = date.size();
    
        int i = 0;
        while (i < n && isdigit(date[i])) ++i;
        int day = stoi(date.substr(0, i));

        while (i < n && date[i] != ' ') ++i;
        while (i < n && date[i] == ' ') ++i;
        int j = i;
        while (j < n && date[j] != ' ') ++j;
        cout << date.substr(i, j - i) << "\n";
        int month = months.at(date.substr(i, j - i));

        i = j;
        while (i < n && date[i] == ' ') ++i;
        int year = stoi(date.substr(i));

        auto two_digits = [](int num) {
            auto s = to_string(num);
            if (s.size() == 1) s = "0" + s;
            return s;
        };

        return to_string(year) + '-' + two_digits(month) + '-' + two_digits(day);
    }
};
