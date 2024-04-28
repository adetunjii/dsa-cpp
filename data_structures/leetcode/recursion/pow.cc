#include <iostream>

using namespace std;

double pow(double x, int n) {
	if (x == 0) return 0;
	if (n == 0) return 1;
	if (n == 1) return x;
	if (n == -1) return 1/x;

	return n % 2 == 0 ? pow(x*x, n/2) : x * pow(x, n-1);
}

int main() {

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		while (cin.peek() != '\n' && cin.peek() != EOF) {
			double x; int n;
			cin >> x >> n;

			cout << pow(x, n) << "\n";
		}
		cin.ignore();
	}

	return 0;
}