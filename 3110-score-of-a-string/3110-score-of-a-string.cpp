class Solution {
public:
    int scoreOfString(string s) {
        int len = s.size();
        int score = 0;
        for (int i = 1; i < len; i++) {
            score += abs((int)s[i - 1] - (int)s[i]);
        }
        return score;
    }
};