class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        unordered_set<int> set2;

        int n = nums1.size();
        int m = nums2.size();

        for (int i = 0; i < 100; ++i) {
            if (i >= n && i >= m)
                break;
            if (i < n)
                set1.insert(nums1[i]);
            if (i < m)
                set2.insert(nums2[i]);
        }

        int count1 = 0;
        int count2 = 0;

        for (int i = 0; i < 100; ++i) {
            if (i >= n && i >= m)
                break;
            if (i < n && set2.count(nums1[i])) {
                count1++;
            }
            if (i < m && set1.count(nums2[i])) {
                count2++;
            }
        }
        return {count1, count2};
    }
};
