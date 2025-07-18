class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = -1;
        string res = word;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == ch) {
                index = i;
                break;
            }
        }
        if (index == -1)
            return word;
        for (int i = 0, j = index; i <= index; i++, j--) {
            res[i] = word[j];
        }
        return res;
    }
};