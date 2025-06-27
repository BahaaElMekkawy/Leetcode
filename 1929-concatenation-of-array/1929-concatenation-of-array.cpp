class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len); // Intialize with the len because insert will
                              // increase the size each time
        for (int i = 0; i < len; ++i) {
            res[i] = nums[i];
            res.insert(res.begin() + (len + i), nums[i]);
        }
        return res;
    }
};