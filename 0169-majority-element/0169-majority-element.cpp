class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> numbers;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (numbers.count(nums[i]) > 0)
                numbers[nums[i]]++;
            else
                numbers[nums[i]] = 1;
        }
        int maj = 0;
        for (auto& pair : numbers) {
            if (pair.second > len / 2)
                maj = pair.first;
        }
        return maj;
    }
};