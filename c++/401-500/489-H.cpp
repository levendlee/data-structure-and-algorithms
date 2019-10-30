/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
private:
    unordered_set<uint64_t> cleaned_;
    static constexpr int moves_[4][2] = {{0,-1}, {1,0}, {0,1}, {-1,0}};

public:
    void dfs(Robot& robot, int64_t x, int64_t y, int dir) {
        //std::cout << x << "," << y << "\n";
        // trun left in a loop
        for (int i = 0; i < 4; ++i) {
            auto ndir = (dir + i) % 4;
            auto nx = x + moves_[ndir][0];
            auto ny = y + moves_[ndir][1];
            auto nloc = (uint64_t(nx) << 32) | uint64_t(ny);
            //std::cout << nloc << "#\n";
            if (!cleaned_.count(nloc)) {
                cleaned_.insert(nloc);
                if (robot.move()) {
                    robot.clean();
                    dfs(robot, nx, ny, ndir);
                    robot.turnLeft();
                    robot.turnLeft();
                }
            }
            robot.turnLeft();
        }
        // return
        robot.turnLeft();
        robot.turnLeft();
        robot.move();
    }

    void cleanRoom(Robot& robot) {
        robot.clean();
        dfs(robot, INT_MAX, INT_MAX, 0);
    }
};