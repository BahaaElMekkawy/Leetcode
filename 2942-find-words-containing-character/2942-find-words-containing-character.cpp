class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int len = words.size();
        vector<int> res;
        for (int i = 0; i < len; ++i) {
            string wordToCheck = words[i];
            for (int j = 0; j < wordToCheck.size(); j++) {
                if (wordToCheck[j] == x) {
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};