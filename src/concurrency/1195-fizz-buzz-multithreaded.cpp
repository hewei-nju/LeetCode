class FizzBuzz {
private:
    int n;

protected:
    atomic<int> cnt;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->cnt = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (this->cnt <= n) {
            if (this->cnt > n)
                return;
            if(this->cnt % 3 != 0 || this->cnt % 5 == 0 ) {
                this_thread::yield();
            } else {
                printFizz();
                this->cnt += 1;
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (this->cnt <= n) {
            if (this->cnt > n)
                return;
            if (this->cnt % 3 == 0 || this->cnt % 5 != 0 ) {
                this_thread::yield();
            } else {
                printBuzz();
                this->cnt += 1;
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (this->cnt <= n) {
            if (this->cnt > n)
                return;
            if (this->cnt % 3 != 0 || this->cnt % 5 != 0) {
                this_thread::yield();
            } else {
                printFizzBuzz();
                this->cnt += 1;
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (this->cnt <= n) {
            if (this->cnt > n)
                return;
            if (this->cnt % 3 == 0 || this->cnt % 5 == 0) {
                this_thread::yield();
            } else {
                printNumber(this->cnt);
                this->cnt += 1;
            }
        }
    }
};