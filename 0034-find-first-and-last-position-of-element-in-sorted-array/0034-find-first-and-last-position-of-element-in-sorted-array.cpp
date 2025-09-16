class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        int last = nums.size() - 1;
        for (int first = 0; first < nums.size(); ++first) {
            if (nums[first] == target && res[0] == -1)
                res[0] = first;
            if (nums[last] == target && res[1] == -1)
                res[1] = last;
            last -= 1;
        }
        return res;
    }
};