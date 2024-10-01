#include <iostream>
#include <thread>
#include <vector>
#include <condition_variable>

std::vector<int> sharedWork;
std::mutex mut;
std::condition_variable condVar;

bool isReady{false};

void producer() {
    // do some work
    constexpr int work = 2;
    sharedWork = {1, 0, 3};
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    {
        std::lock_guard<std::mutex> lock(mut);
        isReady = true; // change the state
    }
    condVar.notify_one(); // notify another thread about the change. 
}

void worker() {
    std::cout << "Waiting " << '\n';

    std::unique_lock<std::mutex> lock(mut);
    if (!isReady) {
        condVar.wait(lock); // blocks until isReady is true.
    }

    sharedWork[1] = 2;
    std::cout << "Done " << '\n';
}

int main() {
    std::cout << '\n';

    std::thread t1(producer);
    std::thread t2(worker);

    t1.join();
    t2.join();

    for (auto v : sharedWork) {
        std::cout << v << " ";
    }

    std::cout << "\n\n";
}
