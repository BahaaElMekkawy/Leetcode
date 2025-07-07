// Approach:
// We iterate through the nums2 vector from left to right.
// For each element:
//   - If the stack is empty, or the current number is smaller than the top of the stack,
//     we push it because we haven't found its next greater element yet.
//   - If the current number is greater than the top of the stack,
//     then this current number is the "next greater element" for the top of the stack.
//     We pop the top, store the mapping in a hash map (greater[top] = current),
//     and continue popping while the current number is still greater than stack.top().
// We repeat this process for all elements in nums2.
// By the end, any numbers left in the stack do not have a next greater element,
// so we map them to -1.
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> greater;
        int len = nums2.size();
        int len1 = nums1.size();
        vector<int> res(len1);

        for (int i = 0; i < len; ++i) {
            greater[nums2[i]] = -1;
            while (!st.empty() && nums2[i] > st.top()) {
                greater[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        for (int i = 0; i < len1; i++) {
            res[i] = greater[nums1[i]];
        }
        return res;
    }
};