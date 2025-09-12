class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> ToS;
        unordered_map<char, char> FromS;
        for (int i = 0; i < s.size(); ++i) {
            char _s = s[i];
            char _t = t[i];
            if (ToS.count(_t) && ToS[_t] != _s)
                return false;
            if (FromS.count(_s) && FromS[_s] != _t)
                return false;

            ToS[_t] = _s;
            FromS[_s] = _t;
        }
        return true;
    }
};