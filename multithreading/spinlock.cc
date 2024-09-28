// SPINLOCKS
// Assume you have a resource that requires a lock. The thread
// tries to acquire the lock but it fails, now the thread is blocked(cannot proceed).
//
// Instead of the thread to be pre-empted (removed in favor of another thread to be executed),
// a SpinLock keeps the thread busy by continuously checking the state of the lock to see if it is free.
// This is useful when you are certain that the lock would only be unavailable for a very short period
// and pre-emption would take longer time.
// 
// SpinLocks should not be used in single processor systems because it can lead to a deadlock - the other
// thread that has acquired the lock cannot proceed and the current thread is keeping the CPU busy doing nothing
// and is not pre-empted.

#include <atomic>
#include <thread>

class SpinLock {
private: 
    std::atomic_flag flag = ATOMIC_FLAG_INIT;
public:
    void lock() {
        while (flag.test_and_set()); // sets the value of the flag to true and returns the previous value of the flag.
    }

    void unlock() {
        flag.clear();   // sets the value of the flag to false.
    }
};

SpinLock spin;

void workOnResource() {
    spin.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    spin.unlock();
}

int main() {
    std::thread A(workOnResource);
    std::thread B(workOnResource);

    A.join(); 
    B.join();
}