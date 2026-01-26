#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// int ways = 0;

// bool isSafe(vector<string>& board, int row, int col) {
// 	int n = board.size();
// 	for (int i = 0; i < n; i++) {
// 		if (board[i][col] == 'Q') return false;
// 		if (row - i >= 0 && col - i >= 0 && (board[row-i][col-i] == 'Q')) return false;
// 		if (row - i >= 0 && col + i < n && (board[row-i][col+i] == 'Q')) return false;
// 	}
// 	return true;
// }

// void solve(vector<string>& board, int row) {
// 	int n = board.size();
// 	if (row == n) {
// 		ways += 1;
// 		return;
// 	}

// 	for (int col = 0; col < n; col++) {
// 		if (isSafe(board, row, col)) {
// 			if (board[row][col] == '*') continue;

// 			board[row][col] = 'Q';
// 			solve(board, row+1);
// 			board[row][col] = '.'; // backtrack
// 		}
// 	}
// }

// int main () {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	vector<string> board;
// 	string ln;
// 	while (getline(cin, ln)) {
// 		board.push_back(ln);
// 	}

// 	solve(board, 0);
// 	cout << ways << "\n";

// 	return 0;
// }