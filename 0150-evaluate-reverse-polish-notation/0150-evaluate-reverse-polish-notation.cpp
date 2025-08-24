// Approach:
// - Use a stack to evaluate the Reverse Polish Notation (RPN).
// - Traverse through each token:
//     - If the token is a number → convert to int and push onto the stack.
//     - If the token is an operator (+, -, *, /):
//         - Pop the top two numbers from the stack (order matters!).
//         - Apply the operation.
//         - Push the result back to the stack.
// - At the end, the stack will contain the final result (stack top).
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int len = tokens.size();
        stack<int> res;
        for (int i = 0; i < len; ++i) {
            string cur = tokens[i];
            if (isOperand(cur)) {
                int num1 = res.top();res.pop();
                int num2 = res.top();res.pop();
                int evaluation = evaluate(num2, num1, cur);
                res.push(evaluation);
            } else {
                res.push(stoi(cur));
            }
        }
        return res.top();
    }

    bool isOperand(string ch) {
        return (ch == "+" || ch == "-" || ch == "*" || ch == "/");
    }
    int evaluate(int a, int b, const string& op) {
        if (op == "+")
            return a + b;
        else if (op == "-")
            return a - b;
        else if (op == "*")
            return a * b;
        else
            return a / b;
    }
};