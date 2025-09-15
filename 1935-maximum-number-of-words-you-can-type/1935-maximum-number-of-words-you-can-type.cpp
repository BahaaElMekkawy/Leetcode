class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken;
        for (int i = 0; i < brokenLetters.size(); ++i) {
            broken.insert(brokenLetters[i]);
        }

        int count = 0, i =0 , n = text.size();   
        while (i < n) {
            bool canType = true;
            int j = i;
            while (j < n && text[j] != ' ') {
                if (broken.count(text[j])) {
                    canType = false;
                }
                j++;
            }
            if (canType)
                count++;
            i = j + 1; // move to the next word 
        }
        return count;
    }
};
