class Solution {
public:
    int findClosest(int x, int y, int z) {
        int p1 = abs(x - z), p2 = abs(y - z);
        if (p1 == p2)
            return 0;
        if (p1 > p2)
            return 2;
        else
            return 1;
    }
};