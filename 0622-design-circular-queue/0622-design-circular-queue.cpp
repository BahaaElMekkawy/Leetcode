class MyCircularQueue {
private:
    int addedElements = 0;
    int front = 0;
    int rear = 0;
    int size;
    int* arr;

public:
    MyCircularQueue(int k) {
        size = k;
        arr = new int[k];
    }

    bool enQueue(int value) {
        if (isFull())
            return false;
        if (!isEmpty()) {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
        addedElements++;
        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;
        // this condition check if the the front is the last element so to
        // decide whether to move front or leave it at the first
        if (addedElements > 1)
            front = (front + 1) % size;
        addedElements--;
        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    int Rear() {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    bool isEmpty() { return addedElements == 0; }

    bool isFull() { return addedElements == size; }
};