class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string firstString = strs[0];
        int len = firstString.size();
        string res;
        for (int i = 0; i < len; i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j - 1][i] != strs[j][i])
                    return res;
            }
            res += firstString[i];
        }
        return res;
    }
};