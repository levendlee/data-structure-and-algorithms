class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if (startGene == endGene) {
            return 0;
        }

        const int n = bank.size();
        vector<bool> used(n, false);

        queue<string> bfs;
        bfs.push(startGene);

        int steps = 0;
        while (!bfs.empty()) {
            ++steps;
            int num_paths = bfs.size();
            for (int k = 0; k < num_paths; ++k) {
                string start = bfs.front();
                bfs.pop();
                for (int i = 0; i < n; ++i) {
                    if (used[i]) {
                        continue;
                    }
                    int diffs = 0;
                    for (int j = 0; j < start.size(); ++j) {
                        diffs += bank[i][j] != start[j];
                    }
                    if (diffs == 1) {
                        used[i] = true;
                        if (bank[i] == endGene) {
                            return steps;
                        }
                        bfs.push(bank[i]);
                    }
                }
            }
        }

        return -1;
    }
};
