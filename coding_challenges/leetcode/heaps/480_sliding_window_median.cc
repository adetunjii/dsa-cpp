#include <map>
#include <queue>
#include <vector>

std::vector<double> medianSlidingWindow(std::vector<int>& nums, int k) {
    int N = nums.size();

    std::priority_queue<double> maxHeap;
    std::priority_queue<double, std::vector<double>, std::greater<double>> minHeap;
    std::vector<double> res;
    std::map<double, int> m;

    for (int i = 0; i < k; i++) {
        maxHeap.push(nums[i]);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double previousMedian = 0;
    if (k & 1) {
        previousMedian = maxHeap.top();
    } else {
        previousMedian = (maxHeap.top() + minHeap.top()) / 2.0;
    }

    res.push_back(previousMedian);

    int balance = 0;
    for (int r = k; r < N; r++) {
        int l = r - k;

        m[nums[l]] += 1;

        if (nums[l] <= previousMedian) {
            balance = -1;
        } else {
            balance = 1;
        }

        if (nums[r] <= previousMedian) {
            balance += 1;
            maxHeap.push(nums[r]);
        } else {
            balance -= 1;
            minHeap.push(nums[r]);
        }

        if (balance < 0) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        } else if (balance > 0) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        while (!maxHeap.empty() && m[maxHeap.top()] > 0) {
            m[maxHeap.top()] -= 1;
            maxHeap.pop();
        }

        while (!minHeap.empty() && m[minHeap.top()] > 0) {
            m[minHeap.top()] -= 1;
            minHeap.pop();
        }

        if (k & 1) {
            previousMedian = maxHeap.top();
        } else {
            previousMedian = (maxHeap.top() + minHeap.top()) / 2.0;
        }

        res.push_back(previousMedian);
    }

    return res;
}