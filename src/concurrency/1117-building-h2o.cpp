class H2O {
protected:
    atomic<int> hnum = 0;
    atomic<int> onum = 0;

public:
    H2O(){ }

    void hydrogen(function<void()> releaseHydrogen)
    {
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        while (hnum == 2 && onum == 0) {
            this_thread::yield();
        }
        if (onum == 1 && hnum == 2) {
            hnum = 0;
            onum = 0;
        }
        releaseHydrogen();
        hnum += 1;
    }

    void oxygen(function<void()> releaseOxygen)
    {

        // releaseOxygen() outputs "O". Do not change or remove this line.
        while (onum == 1 && hnum != 2) {
            this_thread::yield();
        }
        if (onum == 1 && hnum == 2) {
            hnum = 0;
            onum = 0;
        }
        releaseOxygen();
        onum += 1;
    }
};