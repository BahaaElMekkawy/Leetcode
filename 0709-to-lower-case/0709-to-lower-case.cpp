class Solution {
public:
    string toLowerCase(string s) {
        string res = s;  
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                res[i] = s[i] + 32; // convert to lowercase manually
            }
        }
        return res;
    }
};
