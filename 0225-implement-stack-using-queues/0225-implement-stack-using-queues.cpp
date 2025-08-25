// Approach:
// We simulate a stack (LIFO) using a single queue (FIFO).
// The trick: When pushing a new element, we insert it at the back of the queue,
// then rotate the queue so that the new element comes to the front.
// This ensures the queue's front always represents the "top" of the stack.
// 
// Complexity:
// - push(x): O(n) (due to rotation)
// - pop(): O(1)
// - top(): O(1)
// - empty(): O(1)

class MyStack {
public:
    queue<int> q;
    MyStack() {}

    void push(int x) {
        q.push(x);
        int y = q.size();
        while (y-- > 1) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }

    int top() { return q.front(); }

    bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */