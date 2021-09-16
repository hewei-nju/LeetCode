class FooBar {
private:
    int n;

protected:
    atomic<bool> flag;

public:
    FooBar(int n)
    {
        this->n = n;
        flag = true;
    }

    void foo(function<void()> printFoo)
    {

        for (int i = 0; i < n; i++) {
            // printFoo() outputs "foo". Do not change or remove this line.
            while (!flag) {
                this_thread::yield();
            }
            printFoo();
            flag = false;
        }
    }

    void bar(function<void()> printBar)
    {

        for (int i = 0; i < n; i++) {
            // printBar() outputs "bar". Do not change or remove this line.
            while (flag) {
                this_thread::yield();
            }
            printBar();
            flag = true;
        }
    }
};