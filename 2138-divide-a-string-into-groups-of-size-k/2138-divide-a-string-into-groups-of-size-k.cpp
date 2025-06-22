class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int len = s.size();
        for (int i = 0; i < len; i += k) {
           string sub_string = s.substr(i , k);
           int size =sub_string.size();
           if ( size< k )
                sub_string.append(k-size , fill); // add chars with fill char to the end 
           res.push_back(sub_string);
        }
        return res;
    }
};