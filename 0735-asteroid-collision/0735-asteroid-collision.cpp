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