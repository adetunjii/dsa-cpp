#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int compareLists(vector<int> &A, vector<int> &B) {
  unordered_map<int, int> m;
  for (int num : B) {
    m[num] += 1;
  }

  int score = 0;
  for (int num : A) {
    score += m[num] * num;
  }

  return score;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin.tie(nullptr);

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