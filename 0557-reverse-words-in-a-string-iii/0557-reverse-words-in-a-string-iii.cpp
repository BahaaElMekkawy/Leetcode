class Solution {
public:
    string reverseWords(string s) {
        stack<char> stack;
        int len = s.size();
        string res;
        int i = 0;
        while (i < len) {
            if (s[i] != ' ')
                stack.push(s[i]);
            else {
                while (!stack.empty()) {
                    res += stack.top();
                    stack.pop();
                }
                res+= " ";
            }
            i++;
        }
        while (!stack.empty()) {
            res += stack.top();
            stack.pop();
        }
        return res;
    }
};