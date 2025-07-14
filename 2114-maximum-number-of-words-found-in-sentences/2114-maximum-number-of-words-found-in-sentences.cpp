class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = 0;

        for (int i = 0; i < sentences.size(); i++) {
            int spaceCount = 0;
            string sentence = sentences[i];

            for (int j = 0; j < sentence.length(); j++) {
                if (sentence[j] == ' ') {
                    spaceCount++;
                }
            }

            int wordCount = spaceCount + 1;
            if (wordCount > maxWords) {
                maxWords = wordCount;
            }
        }

        return maxWords;
    }
};
