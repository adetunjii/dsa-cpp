#include <queue>

class MedianFinder {
private:
    std::priority_queue<int> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<>> minHeap;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        maxHeap.push(num);
        if (minHeap.size() < maxHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;    
    }
};