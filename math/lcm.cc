#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  // swap positions
  if (a < b) {
    int t = a;
    a = b;
    b = t;
  }

  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }

  return a;
}

int LCM(vector<int> &inputs) {
  if (inputs.size() == 0)
    return 0;

  if (inputs.size() == 1)
    return inputs[0];

  int result = inputs[0] * inputs[1] / gcd(inputs[0], inputs[1]);
  for (int i = 2; i < inputs.size(); i++) {
    vector<int> r = {result, inputs[i]};
    result = LCM(r);
  }

  return result;
}

int main() {

  vector<int> in = {10, 25};
  cout << LCM(in) << endl;
  return 0;
}