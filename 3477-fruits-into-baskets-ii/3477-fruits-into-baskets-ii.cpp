class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count = fruits.size();
        unordered_set<int> usedBaskets; 

        for (int i = 0; i < fruits.size(); i++) {
            int minIndex = -1;

            for (int j = 0; j < baskets.size(); j++) {
                if (fruits[i] <= baskets[j] && usedBaskets.count(j) == 0) {
                    if (minIndex == -1 || j < minIndex) {
                        minIndex = j;
                    }
                }
            }

            if (minIndex != -1) {
                count--;  
                usedBaskets.insert(minIndex);
            }
        }

        return count;
    }
};
