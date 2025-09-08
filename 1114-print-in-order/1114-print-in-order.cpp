class Foo {
    private :
    promise<void> p1;
    promise<void> p2;
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        printFirst();
        p1.set_value(); // mark as complete, the printSecond will be waited until p1 is completed.
    }

    void second(function<void()> printSecond) {
        p1.get_future().wait();  // Wait for p1 to finish
        printSecond();
        p2.set_value();
    }

    void third(function<void()> printThird) {
        p2.get_future().wait();  // Wait for p2 to finish
        printThird();
    }
};