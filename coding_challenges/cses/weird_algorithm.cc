#include <iostream>
#include <vector>

using namespace std;

void solve(int64_t n) {

	while (n != 1) { 
		cout << n << " "; 
		n = n & 1LL ? (n*3) + 1 : n / 2;
	}
	cout << n << "\n";
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		while (cin.peek() != '\n' && cin.peek() != EOF) { 
			// do some work
		}

	return 0;
}