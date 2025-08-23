class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size() - 1;
        int start = 0;
        int end = len;
        int middle;
        while (start <= end) {
            middle = (start + end) / 2;
            if (nums[middle] == target)
                return middle;
            else if (nums[middle] > target)
                end = middle - 1;
            else if (nums[middle] < target)
                start = middle + 1;
        }
        return -1;
    }
};