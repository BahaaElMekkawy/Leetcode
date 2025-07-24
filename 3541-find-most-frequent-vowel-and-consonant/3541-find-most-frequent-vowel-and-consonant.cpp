class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freq;
        int maxVowels = 0;
        int maxConsonants = 0;
        for (int i = 0; i < s.size(); ++i) {
            int c = s[i];
            freq[c]++;
        }
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            char c = it->first;
            int count = it->second;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                if (maxVowels < count)
                    maxVowels = count;
            } else {
                if (maxConsonants < count)
                    maxConsonants = count;
            }
        }

        return maxVowels + maxConsonants;
    }
};