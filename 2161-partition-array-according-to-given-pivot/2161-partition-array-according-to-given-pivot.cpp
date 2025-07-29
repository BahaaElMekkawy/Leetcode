class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, greater;

        for (int n : nums) {
            if (n < pivot)
                less.push_back(n);
            else if (n == pivot)
                equal.push_back(n);
            else
                greater.push_back(n);
        }

        vector<int> res;
        res.insert(res.end(), less.begin(), less.end());
        res.insert(res.end(), equal.begin(), equal.end());
        res.insert(res.end(), greater.begin(), greater.end());

        return res;
    }
};

//Another Approach (Two Pointers)
    // vector<int> pivotArray(vector<int>& nums, int pivot) {
    //     int n = nums.size();
    //     vector<int> res(n);
    //     int left = 0, right = n - 1;

    //     // First pass: place all elements > pivot at the end (right pointer)
    //     for (int i = n - 1; i >= 0; --i) {
    //         if (nums[i] > pivot) {
    //             res[right--] = nums[i];
    //         }
    //     }

    //     // Second pass: place all elements < pivot at the beginning (left pointer)
    //     for (int i = 0; i < n; ++i) {
    //         if (nums[i] < pivot) {
    //             res[left++] = nums[i];
    //         }
    //     }

    //     // Fill pivot values in the middle
    //     while (left <= right) {
    //         res[left++] = pivot;
    //     }

    //     return res;
    // }
