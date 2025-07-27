/*
 * Approach:
 * 1. Split the input string `s` into individual words using a string stream.
 * 2. Check if the number of words matches the length of the pattern.
 *    - If not, return false immediately.
 * 3. Use two hash maps:
 *    - `wordToChar` to map each word to a character.
 *    - `charToWord` to map each character to a word.
 * 4. Iterate through the pattern and corresponding words:
 *    - If a mapping already exists, ensure it matches the current word/char.
 *    - If a mapping doesn't exist, add it to both maps.
 * 5. If all mappings are consistent, return true; otherwise, return false.
 */
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> wordToChar;
        unordered_map<char, string> charToWord;
        vector<string> words;

        for (int i = 0, j = 0; i < s.size() && j <= s.size(); ++i) {
            string word = "";
            while (j < s.size() && s[j] != ' ') {
                word += s[j++];
            }
            words.push_back(word);
            j++; 
        }

        if (words.size() != pattern.size()) {
            return false;
        }

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            if (wordToChar.count(w) && wordToChar[w] != c) {
                return false;
            }
            if (charToWord.count(c) && charToWord[c] != w) {
                return false;
            }

            wordToChar[w] = c;
            charToWord[c] = w;
        }
        return true;
    }
};