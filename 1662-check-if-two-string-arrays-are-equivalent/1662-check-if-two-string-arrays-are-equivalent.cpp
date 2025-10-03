class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1, w2;
        for (int i = 0; i < word1.size(); ++i) {
            string cur = word1[i];
            w1 += cur;
        }
        for (int i = 0; i < word2.size(); ++i) {
            string cur = word2[i];
            w2 += cur;
        }
        return w1 == w2 ; 
    }
};