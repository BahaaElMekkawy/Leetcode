class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        stack<char> stack;
        unordered_map<char, char> map;
        map['('] = ')';
        map['{'] = '}';
        map['['] = ']';

        for (int i = 0; i < len; i++) {
            char temp = s[i];
            if (stack.empty())
                stack.push(temp);
            else {
                char toCheck = stack.top();
                if (map[toCheck] == temp)
                    stack.pop();
                else
                    stack.push(temp);
            }
        }
        return stack.empty();
    }
};