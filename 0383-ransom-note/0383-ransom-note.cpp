class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> noteMap;
        unordered_map<char, int> magazineMap;
        if (ransomNote.size() > magazine.size())
            return false;
        for (int i = 0; i < magazine.size(); ++i) {
            if (i < ransomNote.size())
                noteMap[ransomNote[i]]++;
            magazineMap[magazine[i]]++;
        }
        for (int i = 0; i < ransomNote.size(); ++i) {
            char toCheck = ransomNote[i];
            if (noteMap[toCheck] > magazineMap[toCheck])
                return false;
        }
        return true;
    }
};