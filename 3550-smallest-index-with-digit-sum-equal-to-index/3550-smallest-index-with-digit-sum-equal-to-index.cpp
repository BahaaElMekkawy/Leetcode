class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int minIndex = -1;
        for (int i = 0; i < nums.size(); i++) {
            int number = nums[i];
            int sum = 0;
            while (number != 0) {
                sum += number % 10;
                number /= 10;
            }
            if (sum == i) {
                if (minIndex == -1)
                    minIndex = i;
                else if (sum < minIndex)
                    minIndex = i;
            }
        }
        return minIndex;
    }
};