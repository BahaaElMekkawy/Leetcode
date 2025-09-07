// Approach
//   - Maintain a "window" [left, right] of unique characters.
//   - Expand the window by moving right forward.
//   - If s[right] is already in the set (duplicate):
//        * Shrink the window from the left side
//          (erase s[left], left++) until the duplicate is gone.
//   - Update max length at each step.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_set<char> seen;
        int counter = 0;
        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            while (seen.count(s[right])) {
                seen.erase(s[left++]);
            }
            seen.insert(s[right]);
            counter++;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
