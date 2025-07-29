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
