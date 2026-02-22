#include <queue>

namespace queue {

class RecentCounter {
private:
    std::queue<int> q;
public:
    RecentCounter() {}
    
    int ping(int t) {
        int A = t - 3000;
        q.push(t);

        while(!q.empty() && A > q.front()) q.pop();

        return q.size();
    }
};
}