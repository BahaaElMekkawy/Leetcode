class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int maxProfit = 0;
        int minPrice = INT_MAX;
        for (int i = 1; i <= len ; i++) {
            if (minPrice > prices[i-1])
                minPrice = prices[i-1];
            int profit = prices[i-1] - minPrice;
            if (profit > maxProfit)
                maxProfit = profit;
        }
        return maxProfit;
    }
};

// Soultion With Time Exceeded
// int len = prices.size();
// int maxProfit = 0;
// for (int i = 0; i < len - 1; i++) {
//     for (int j = len - 1; j > i; j--) {
//         int profit = prices[j] - prices[i];
//         if (profit > maxProfit)
//             maxProfit = profit;
//     }
// }
// return maxProfit;