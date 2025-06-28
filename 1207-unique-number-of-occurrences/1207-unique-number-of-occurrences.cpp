class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int len = arr.size();
        unordered_map<int, int> map;
        for (int i = 0; i < len; i++) {
            map[arr[i]]++;
        }

        unordered_set<int> seen;
        for (auto& pair : map) {
            if (seen.count(pair.second)) {
                return false;
            }
            seen.insert(pair.second);
        }
        return true ;
    }
};