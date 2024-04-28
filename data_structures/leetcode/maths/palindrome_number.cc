#include <iostream>

using namespace std;

bool isPalindrome(int x) {
	if (x <= 10) return false;

	// use long long to avoid overflow error
	long long rev = 0;
	while (x > 0) {
		rev = rev * 10 + x % 10;
		x = x/10;
	}

	return rev == x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		while (cin.peek() != '\n' && cin.peek() != EOF) {
			int num;
			cin >> num;
			if (num > 0) cout << isPalindrome(num) << "\n";
		}
		cin.ignore();

	}

	return 0;
}