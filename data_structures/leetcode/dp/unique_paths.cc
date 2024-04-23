#include <iostream>
#include <sstream>

using namespace std;

int uniquePaths(int m, int n) {
	if (m == 0 || n == 0) return 0;
	if (m == 1 && n == 1) return 1;

	vector<vector<int>> A(2, vector<int>(n, 1));
	int row, col;
	row = 1;
	while (row < m) {
		col = 1;
		while (col < n) {
			A[1][col] = A[0][col] + A[1][col -1];
			col += 1;
		}
		swap(A[0], A[1]);
		A[1][0] = 1;
		row += 1;
	}

	return A[0][n-1];
}


int main() {
	int M, N;
	cin >> M >> N;
	cout << uniquePaths(M, N) << "\n";

	return 0;
}