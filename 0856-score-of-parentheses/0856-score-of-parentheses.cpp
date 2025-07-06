/*
Approach:
   - We use a stack to simulate evaluating nested parentheses:
     - When we see '(', we push 0 to mark a new "frame" of computation.
     - When we see ')', we pop the top of the stack:
         - If the popped value is 0 → it means we had "()", so we push 1.
         - If it's not 0 → it means we had a nested expression like "(A)", so we
            push 2 * popped_value.
    - Then we add this computed score to the previous frame (by popping and
pushing the updated sum).
*/

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(')
                st.push(0);
            else {
                int last = st.top();
                st.pop();
                if (last == 0)
                    last = 1;
                else
                    last *= 2;
                int parent_par = st.top() + last;
                st.pop();
                st.push(parent_par);
            }
        }
        return st.top();
    }
};