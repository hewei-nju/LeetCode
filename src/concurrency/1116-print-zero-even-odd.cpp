class ZeroEvenOdd {
private:
    int n;
    atomic<int> flag = 0;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; ++i) {
            while (flag != 0) {
                this_thread::yield();
            }
            printNumber(0);
            if (i & 1) {
                flag = 1;
            } else {
                flag = 2;
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            while (flag != 2) {
                this_thread::yield();
            }
            printNumber(i);
            flag = 0;
        } 
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            while (flag != 1) {
                this_thread::yield();
            }
            printNumber(i);
            flag = 0;
        }
    }
};