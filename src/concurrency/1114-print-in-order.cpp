#include <semaphore.h>

class Foo {
protected:
    sem_t sem_1;
    sem_t sem_2;

public:
    Foo() {
        sem_init(&sem_1, 0, 0);
        sem_init(&sem_2, 0, 0);
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&sem_1);
    }

    void second(function<void()> printSecond) {
        sem_wait(&sem_1);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&sem_2);
    }

    void third(function<void()> printThird) {
        sem_wait(&sem_2);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        
    }
};