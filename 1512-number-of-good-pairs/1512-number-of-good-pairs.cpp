// Approach:
// We use a hash map (unordered_map) to count the frequency of each number as we iterate.
// For every occurrence of a number, we can form pairs with all its previous occurrences.
// So, when we see nums[i], we add frequencyMap[nums[i]] to the result and then increment its count.
// This gives us the number of good pairs directly in one pass
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        int len = nums.size();
        unordered_map<int,int> frequencyMap(len);
        for (int i = 0; i < len; ++i) {
            count +=frequencyMap[nums[i]]++;
        }
        return count ;
    }
};