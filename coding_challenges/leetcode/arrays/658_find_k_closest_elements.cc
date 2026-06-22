#include <vector>

std::vector<int> findClosestElementsTwoPointer(std::vector<int>& A, int k, int x) {
    int N = A.size();
    int right = lower_bound(A.begin(), A.end(), x) - A.begin();
    int left = right - 1;

    for (int i = 0; i < k; i++) {
        if (left < 0) {
            right += 1;
        } else if (right >= N) {
            left -= 1;
        } else {
            if (x - A[left] <= A[right] - x) {
                left -= 1;
            } else {
                right += 1;
            }
        }
    }

    // we use left + 1 because we need to trim the excess loop step at the end.
    return std::vector<int>(A.begin() + left + 1, A.begin() + right);
}

std::vector<int> findClosestElements(std::vector<int>& A, int k, int x) {
    int left = 0;
    int right = A.size() - k;

    while (left < right) {
        int mid = (left + right) / 2;

        if ((x - A[mid]) > (A[mid + k] - x)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return std::vector<int>(A.begin() + left, A.begin() + left + k);
}