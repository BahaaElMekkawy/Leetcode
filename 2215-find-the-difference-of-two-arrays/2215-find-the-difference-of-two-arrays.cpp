class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> distinct1;
        unordered_set<int> distinct2;
        for (int i = 0; i < nums1.size(); i++) {
            distinct1.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++) {
            distinct2.insert(nums2[i]);
        }
        vector<int> res1;
        vector<int> res2;
        for (int num : distinct1) {
            if (distinct2.count(num) == 0) {
                res1.push_back(num);
            }
        }
        for (int num : distinct2) {
            if (distinct1.count(num) == 0) {
                res2.push_back(num);
            }
        }

        return {res1, res2};
    }
};