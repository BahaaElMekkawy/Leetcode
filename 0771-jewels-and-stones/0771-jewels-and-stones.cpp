class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> set;
        int count = 0;
        for (int i = 0; i < jewels.size(); ++i) {
            set.insert(jewels[i]);
        }
        for (int i = 0; i < stones.size(); ++i) {
            if (set.count(stones[i]))
                count++;
        }
        return count;
    }
};