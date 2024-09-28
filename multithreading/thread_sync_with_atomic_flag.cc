#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

std::vector<int> myVec{};

std::atomic_flag atomic_flag{};

void prepareWork() {
    myVec.insert(myVec.end(), {0,1,0,3});
    std::cout << "Sender:: Data prepared." << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    atomic_flag.test_and_set(); 
    atomic_flag.notify_one(); // notifies other threads using this atomic that it's state has changed.
                             // atomic flags do not have an automatic way to tell other threads about the state of the flag.
                             // Without notify_one() or notify_all(), the other threads using this atomic cannot proceed. 
}

void completeWork() {
    std::cout << "Waiter: Waiting for data." << '\n';
    atomic_flag.wait(false);  // wait -> checks to see if the flag has changed from its old value. In this case false (wait(<old-value>));
    myVec[2] = 2;
    std::cout << "Waiter: Complete the work." << '\n';
    for (auto i: myVec) std::cout << i << '\n';
    std::cout << '\n';
}

int main() {
    std::cout << '\n';

    std::thread t1(prepareWork);
    std::thread t2(completeWork);

    t1.join();
    t2.join();

    std::cout << '\n';
}