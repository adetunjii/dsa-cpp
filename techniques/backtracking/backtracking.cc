#include <iostream>
#include <vector>

using namespace std;

/**
 * Backtracking is a brute force recursive approach.
 * We try out every possible solution recursively
 * 
*/
bool isSafe(vector<string>& board, int row, int col) {
	int n = board.size();

	for (int i = 0; i < n; i++) {
		// check if there's no other queen in the same vertical line
		if (board[i][col] == 'Q') return false;

		if (row - i >= 0 && col - i >= 0 && board[row-i][col-i] == 'Q') return false;
	}

}

void solve(vector<string>& board, int row) {
	int n = board.size();


}

void nQueen(int n) {
	vector<string> board(n, string(n, '.'));
	solve(board, 0);
	return ways;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	cout << nQueen(N) << "\n";

	return 0;
}