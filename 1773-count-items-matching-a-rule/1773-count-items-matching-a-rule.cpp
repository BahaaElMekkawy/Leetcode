class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey,
                     string ruleValue) {
        int number = 0;
        if (ruleKey == "color")
            number = 1;
        else if (ruleKey == "name")
            number = 2;
        int count = 0;
        for (int i = 0; i < items.size(); ++i) {
            vector<string> item = items[i];
            if (item[number] == ruleValue)
                count++;
        }
        return count;
    }
};