// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int lo = 0, hi = 0;

        while (true) {
            int num = reader.get(hi);
            if (num < target) {
                hi = 2 * (hi + 1) - 1;
            } else if (num == target) {
                return hi;
            } else {
                break;
            }
        }
        lo = (hi + 1) / 2 - 1;
        //std::cout << lo << "," << hi << "\n";
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int num = reader.get(mid);
            if (num == target) {
                return mid;
            } else if (num > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return -1;
    }
};