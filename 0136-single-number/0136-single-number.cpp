class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        //int res;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            freq[num]++;
        }

        for (auto& pair : freq) {
            if (pair.second == 1) {
                return pair.first;
            }
        }
        return -1;//for compilation will never be returned
    }
};