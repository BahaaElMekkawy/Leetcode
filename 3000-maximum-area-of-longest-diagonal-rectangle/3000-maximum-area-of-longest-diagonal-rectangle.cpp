class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = -1;
        int maxDiag = -1;

        for (int i = 0; i < dimensions.size(); ++i) {
            vector<int> cur = dimensions[i];
            int curDiag = (cur[0] * cur[0]) + (cur[1] * cur[1]);
            int curArea = cur[0] * cur[1];
            if (curDiag > maxDiag) {
                maxDiag = curDiag;
                maxArea = curArea;
            } else if (curDiag == maxDiag && curArea > maxArea) {
                maxArea = curArea;
            }
        }
        return maxArea;
    }
};