class Solution {
private:
    set<pair<int, int> > visited;
    void goBack(Robot& robot) {
        robot.turnLeft();
        robot.turnLeft();
        robot.move();
        robot.turnLeft();
        robot.turnLeft();
    }
    void helper(Robot& robot, int x, int y, int direction) {
        pair<int, int> offset[4] = {make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1), make_pair(1, 0)}; // 0: up; 1: left; 2: back; 3: right
        if(visited.find(make_pair(x, y)) != visited.end()) {
            return;
        }
        robot.clean();
        visited.insert(make_pair(x, y));
        for(int i = 0; i < 4; i++) {
            if(robot.move()) {
                helper(robot, x + offset[direction].first, y + offset[direction].second, direction);
                goBack(robot);
            }
            robot.turnLeft();
            direction = (direction + 1) % 4;
        }
    }
public:
    void cleanRoom(Robot& robot) {
        helper(robot, 0, 0, 0);
    }
};