/**
 * APPROACH2:
 * - s1 stack: Used for all push operations. New elements are simply pushed
 * here.
 * - s2 stack: Used for pop and peek operations. It holds elements in reverse
 * order (oldest on top).
 *
 * HOW IT WORKS
 * 1. Push(x): Elements are always pushed onto the `input` stack (O(1) time).
 * 2. Pop()/Peek():
 *    - If `output` is empty, we transfer ALL elements from `input` to `output`.
 *    - This reversal (stack LIFO -> LIFO) magically makes the oldest element
 * the top of `output`.
 *    - We then return (or pop) the top of `output`.
 *
 * WHY THIS APPROACH IS BETTER (Amortized Analysis):
 * The initial implementation transferred elements on *every* push, making
 * push() O(n).
 *
 * This optimized version uses "Lazy Transfer":
 * - Push() is always O(1) — we just push to `input`.
 * - Pop/Peek() is USUALLY O(1) if `output` has elements.
 * - Pop/Peek() is O(n) ONLY when `output` is empty, forcing a transfer.
 *
 * CRITICAL INSIGHT (Amortized O(1) Cost):
 * Each element is pushed to `input` once (1 op) and later popped from `input`
 * and pushed to `output` once (2 ops). Thus, each element incurs a total of 3
 * operations in its lifetime. If we have n elements, the total cost for n
 * operations is O(3n) = O(n). Spread over n operations, the average (amortized)
 * cost per operation is O(1).
 *
 * This is far more efficient for sequences of mixed operations, which is the
 * common case.
 */

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {}

    // Push element x to the back of queue.
    void push(int x) { s1.push(x); }

    int pop() {
        shiftStacks();
        int x = s2.top();
        s2.pop();
        return x;
    }

    int peek() {
        shiftStacks();
        return s2.top();
    }

    bool empty() { return s1.empty() && s2.empty(); }

private:
    // Transfer elements from s1 to s2 only when s2 is empty
    void shiftStacks() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
};

// Approach 1
// To maintain correct order in s2, we move all elements from s2 → s1, insert
// the new element into s1, then move everything back into s2.

// This guarantees that the front of the queue is always on top of s2.

// As a result, pop() and peek() operations are O(1).

// However, each push() requires O(n) time due to the shifting of all elements,
// making the approach inefficient for large input sizes. class MyQueue {
// public:
//     stack<int> s1;
//     stack<int> s2;
//     MyQueue() {}

//     void push(int x) {
//         while (!s2.empty()) {
//             s1.push(s2.top());
//             s2.pop();
//         }
//         s1.push(x);
//         while (!s1.empty()) {
//             s2.push(s1.top());
//             s1.pop();
//         }
//     }

//     int pop() {
//         int x = s2.top();
//         s2.pop();
//         return x;
//     }

//     int peek() { return s2.top(); }

//     bool empty() { return s2.empty(); }
// };

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */