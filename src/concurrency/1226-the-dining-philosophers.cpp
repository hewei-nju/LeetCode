class DiningPhilosophers {
protected:
    mutex mutexs[5];

public:
    DiningPhilosophers()
    {
    }

    void wantsToEat(int philosopher,
        function<void()> pickLeftFork,
        function<void()> pickRightFork,
        function<void()> eat,
        function<void()> putLeftFork,
        function<void()> putRightFork)
    {

        int lhs = philosopher;
        int rhs = (lhs + 1) % 5;

        if (philosopher % 2 == 0) {
            mutexs[lhs].lock();
            mutexs[rhs].lock();
            pickLeftFork();
            pickRightFork();
            eat();
            putLeftFork();
            putRightFork();
            mutexs[lhs].unlock();
            mutexs[rhs].unlock();
        } else {
            mutexs[rhs].lock();
            mutexs[lhs].lock();
            pickLeftFork();
            pickRightFork();
            eat();
            putLeftFork();
            putRightFork();
            mutexs[rhs].unlock();
            mutexs[lhs].unlock();
        }
    }
};