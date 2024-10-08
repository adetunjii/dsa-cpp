#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> solutions;

bool isSafe(vector<string>& board, int row, int col) {
	int n = board.size();

	for (int i = 0; i < n; i++) {
		if (board[i][col] == 'Q') return false;

		if (row - i >= 0 && col - i >= 0 && board[row-i][col-i] == 'Q') return false;
		if (row - i >= 0 && col + i < n &&  board[row-i][col+i] == 'Q') return false;
	}

	return true;
}

void solve(vector<string>& board, int row) {
	int n = board.size();

	if (row == n) {
		solutions.push_back(board);
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

vector<vector<string>> solveNQueens(int n) {
	vector<string> board(n, string(n, '.'))
	solve(board, 0)
	return solutions;
}

int main() {
	int n;
	cin >> n;

	vector<vector<string>> res = solveNQueens(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << res[i][j] << "\n";
		}
	}

	cout << ways << "\n";

	return 0;
}