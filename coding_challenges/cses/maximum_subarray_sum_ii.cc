#include <iostream>
#include <vector>

using namespace std;

// int main() {
//     int N, l, r;

//     cin >> N >> l >> r;
//     vector<int> A(200000);

//     for (int i = 0; i < N; i++) {
//         cin >> A[i];
//     }

//     int maxSum = 0, sum = 0;
//     int j = 0, k = 0;
//     while (j < r) {
//         sum += A[j];
//     }

//     maxSum = sum;
//     while (j < N) {
//         while (j - k + 1 > l) {
//            sum -= A[k];
//            maxSum = max(maxSum, sum);
//            k += 1; 
//         }

//         int cur = j - k + 1;
//         while(cur < r && j < N) {
//             sum += A[j];
//             maxSum = max(maxSum, sum);
//             j += 1;
//             cur = j - k + 1;
//         }
//     }
//     return maxSum;
// }