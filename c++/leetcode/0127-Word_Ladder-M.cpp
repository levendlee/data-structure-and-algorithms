class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) {
            return 1;
        }
        
        const int num_words = wordList.size();

        vector<bool> visited(num_words, false);
        queue<int> bfs;
        bfs.push(-1);

        int num_steps = 1;
        while (!bfs.empty()) {
            ++num_steps;

            int num_paths = bfs.size();
            for (int p = 0; p < num_paths; ++p) {
                int idx = bfs.front();
                bfs.pop();
                const string& start = idx >= 0 ? wordList[idx] : beginWord;

                for (int i = 0; i < num_words; ++i) {
                    if (visited[i]) continue;

                    const string& end = wordList[i];
                    int num_diffs = 0;
                    for (int j = 0; j < start.size(); ++j) {
                        num_diffs += start[j] != end[j];
                    }
                    if (num_diffs == 1) {
                        if (end == endWord) {
                            return num_steps;
                        }

                        visited[i] = true;
                        bfs.push(i);
                    }
                }
            }
        }

        return 0;
    }
};
