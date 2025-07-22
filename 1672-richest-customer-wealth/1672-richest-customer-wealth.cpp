class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = INT_MIN;
        for (int i = 0; i < accounts.size(); ++i) {
            int sum = 0;
            vector<int> curAccount = accounts[i];
            for (int j = 0; j < curAccount.size(); j++) {
                sum += curAccount[j];
            }
            if (sum >= max)
                max = sum;
        }
        return max;
    }
};