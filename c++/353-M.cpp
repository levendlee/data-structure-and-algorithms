class SnakeGame {
private:
    vector<vector<bool>> board_;
    vector<vector<int>> food_;
    deque<pair<int, int>> snake_;

public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        board_ = vector<vector<bool>>(width, vector<bool>(height));
        board_[0][0] = true;
        food_ = food;
        std::reverse(food_.begin(), food_.end());
        snake_.push_back({0, 0});
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto head = snake_.front();
        auto& x = head.first;
        auto& y = head.second;
        if (direction == "U") {
            y--;
        } else if (direction == "L") {
            x--;
        } else if (direction == "R") {
            x++;
        } else if (direction == "D") {
            y++;
        }
        if (x < 0 || x >= board_.size() || y < 0 || y >= board_[0].size()) {
            return -1;
        }
        if (food_.empty() || (food_.back()[1] != x) || (food_.back()[0] != y)) {
            auto tail = snake_.back();
            snake_.pop_back();
            board_[tail.first][tail.second] = false;
        } else {
            food_.pop_back();
        }
        if (board_[x][y]) {
            return -1;
        }
        snake_.push_front(head);
        board_[x][y] = true;
        return snake_.size() - 1;
    }
};