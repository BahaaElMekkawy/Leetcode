class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int len = indices.size();
        string res(len, ' ');
        for (int i = 0; i < len; ++i) {
           res[indices[i]] = s[i];
        }
        return res;
    }
};