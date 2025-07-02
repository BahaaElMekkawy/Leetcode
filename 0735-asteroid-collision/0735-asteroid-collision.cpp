// Approach
    // Use a stack to simulate asteroid collisions.
    // For each asteroid, check for collisions with the top of the stack (if moving in opposite directions).
    // Resolve collisions by comparing sizes: larger asteroid survives, equal sizes destroy both.
    // Push surviving asteroids onto the stack.
    // Convert the stack to a vector for the result.
//Key Notes
    // Stack handles right-moving asteroids (> 0)
    // Left-moving asteroids (< 0) trigger collision checks
    // Size comparisons determine destruction
    // Final stack is reversed for correct order

//Ex. [10,5,-3,-50]
//First stack is empty => push 10 [10]
//5 is not negative => push 5 [10,5]
//-3 is negative so check its mass with the top of stack => don't push -3 [10,5]
//-50 is negative so check its mass with the top of stack => pop 5 and check again until stack is empty [10]
//-50 is negative so check its mass with the top of stack => pop 10 end of while loop flag changed and push -50 [-50]
//return [-50]



class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stack;
        for (int asteriod : asteroids) {
            bool is_exploded = false;
            while (!stack.empty() && asteriod < 0 && stack.top() > 0) {
                if (-asteriod > stack.top()) {
                    stack.pop();
                    continue;
                } else if (-asteriod == stack.top()) {
                    stack.pop();
                }
                is_exploded = true;
                break;
            }
            if (!is_exploded) {
                stack.push(asteriod);
            }
        }
        vector<int> result(stack.size());
        for (int i = stack.size() - 1; i >= 0; --i) {
            result[i] = stack.top();
            stack.pop();
        }
        return result;
    }
};