#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int ways;

bool isSafe(vector<string>& board, int row, int col) {
	int n = board.size();

	for (int i = 0; i < n; i++) {
		if (board[i][col] == 'Q') return false;

		if (row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;
		if (row - i >= 0 && col + i < n && board[row - i][col + i] == 'Q') return false;
	}

	return true;
}

void solve(vector<string>& board, int row) {
	int n = board.size();

	if (row == n) {
		ways += 1;
		return;
	}

	for (int col = 0; col < n; col++) {
		if (isSafe(board, row, col)) {
			board[row][col] = 'Q';
			solve(board, row+1);
			board[row][col] = '.';
		}
	}
}

int totalNQueens(int n) {
	ways = 0;
	vector<string> board(n, string(n, '.'));
	solve(board, 0);
	return ways;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int N;
	while (cin >> N) {
		cout << totalNQueens(N) << "\n";
	}

	return 0;
}