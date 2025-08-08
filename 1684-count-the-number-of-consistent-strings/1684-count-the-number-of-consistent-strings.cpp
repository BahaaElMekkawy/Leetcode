class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowedChars(allowed.begin(), allowed.end());
        int count = words.size();
        for (int i = 0; i < words.size(); ++i) {
            int j = 0;
            string word = words[i];
            for (int j = 0; j < word.size(); ++j) {
                if (!allowedChars.count(word[j])) {
                    count--;
                    break;
                }
            }
        }
        return count;
    }
};