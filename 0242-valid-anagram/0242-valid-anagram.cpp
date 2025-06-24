class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        if (s.size() != t.size())
            return false;
        else {
            for (int i = 0; i < s.size(); i++) {
                map[s[i]]++;
                map[t[i]]--;
            }
        }
        for (auto pair : map) {
            if (pair.second != 0)
                return false;
        }
        return true;
    }
};