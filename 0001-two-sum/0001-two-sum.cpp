class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        int k = nums.size();
        for (int i = 0; i < k; ++i) {
            int rem = target - nums[i];
            if (seen.count(rem))
                return {seen[rem], i};
            seen[nums[i]] = i;
        }
        return {};
    }
};