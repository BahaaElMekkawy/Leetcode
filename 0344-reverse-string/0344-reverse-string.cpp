class Solution {
public:
    void reverseString(vector<char>& s) {
        int first = 0 ; 
        int last = s.size()-1;
        while(last > first)
        {
            swap(s[first++] , s[last--]);
        }
    }
};