class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hour_degree = 360 * ((hour + minutes / 60.0) / 12.0);
        double minutes_degree = 360 * (minutes / 60.0);
        double degree = abs(hour_degree - minutes_degree);
        return degree > 180.0 ? 360.0 - degree : degree;
    }
};
