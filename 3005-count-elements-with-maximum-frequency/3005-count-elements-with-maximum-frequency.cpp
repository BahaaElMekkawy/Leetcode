class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        for (int i = 0; i < nums.size(); ++i) {
            freq[nums[i]]++;
            if (freq[nums[i]] > maxFreq)
                maxFreq = freq[nums[i]];
        }
        int res = 0;
        for (int i = 0; i < freq.size(); ++i) {
            if (freq[i] == maxFreq)
                res += maxFreq;
        }
        return res;
    }
};