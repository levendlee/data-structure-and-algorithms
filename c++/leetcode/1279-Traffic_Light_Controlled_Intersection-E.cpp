// 1279 Traffic Light Controlled Intersection
// https://leetcode.com/problems/traffic-light-controlled-intersection

// version: 1; create time: 2020-02-15 17:08:17;
class TrafficLight {
private:
    mutex mtx_;
    bool a_green_;

public:
    TrafficLight() : a_green_(true) {

    }

    void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car
        function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
        function<void()> crossCar    // Use crossCar() to make car cross the intersection
    ) {
        unique_lock<mutex> lk(mtx_);
        if (roadId == 1 && !a_green_) {
            turnGreen();
            a_green_ = true;
        } else if (roadId == 2 && a_green_) {
            turnGreen();
            a_green_ = false;
        }
        crossCar();
        lk.unlock();
    }
};
