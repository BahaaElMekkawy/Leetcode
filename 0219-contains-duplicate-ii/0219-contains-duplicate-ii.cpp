// Approach 2: 
// Instead of storing all indices for each number like below, keep only the most recent index (last seen).
// For each element, check the distance from its last occurrence.
// If the distance <= k, return true immediately.
// This works because if a farther index didn't satisfy the condition, any earlier index also won't.
// Time Complexity: O(n), Space Complexity: O(n).
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastSeen;

        for (int i = 0; i < nums.size(); ++i) {
            if (lastSeen.count(nums[i]) && i - lastSeen[nums[i]] <= k) {
                return true;
            }
            lastSeen[nums[i]] = i; // update last index
        }

        return false;
    }
};


// Approach 1 : 
// Use an unordered_map<int, unordered_set<int>> to store all indices of each number.
// Then, for each number, compare its indices to check if any two are within distance k.
// This ensures correctness but may be less efficient (O(n^2) in wors
// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         unordered_map<int, unordered_set<int>> distinct;
//         for (int i = 0; i < nums.size(); ++i) {
//             distinct[nums[i]].insert(i);
//         }

//         for (int i = 0; i < nums.size(); ++i) {
//             if (distinct.count(nums[i]) && distinct[nums[i]].size() > 1) {
//                 for (int j : distinct[nums[i]]) {
//                     if (i != j && abs(i - j) <= k) {
//                         return true;
//                     }
//                 }
//             }
//         }

//         return false; 
//     }
// };
