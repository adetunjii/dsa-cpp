#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int N = 9;
        vector<int> row(N), col(N), square(N);

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if(board[r][c] == '.') continue;

                int val = board[r][c] - '1';
                int mask = 1 << val;

                if (row[r] & mask || col[c] & mask || square[(r/3) * 3 + c/3]) {
                    return false;
                }

                row[r] |= mask;
                col[c] |= mask;
                square[(r/3) * 3 + c/3] |= mask;
            }
        }

        return true;
    }
};