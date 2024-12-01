#include <iostream>
#include <vector>

using namespace std;

int compareLists(vector<int> &A, vector<int> &B) {
  if (A.size() != B.size())
    return 0;

  // if we do a normal sort, we can achieve this in O(nlogn)
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  int dist = 0;
  for (int i = 0; i < A.size(); i++) {
    dist += abs(A[i] - B[i]);
  }

  return dist;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<int> A;
  vector<int> B;

  int a, b;
  while (cin >> a >> b) {
    A.push_back(a);
    B.push_back(b);
  }

  cout << compareLists(A, B) << endl;

  return 0;
}