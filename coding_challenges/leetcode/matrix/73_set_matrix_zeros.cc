#include <vector>
#include <unordered_set>

namespace matrix {
    inline void sweepRow(std::vector<std::vector<int>>& matrix, int row) {
        int numCols = matrix[0].size();
        std::fill(matrix[row].begin(), matrix[row].end(), 0);
    }

    inline void sweepCol(std::vector<std::vector<int>>& matrix, int col) {
        int numRows = matrix.size();
        for (auto& row : matrix) {
            row[col] = 0;
        }
    }

    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int numRows = matrix.size(), numCols = matrix[0].size();

        if (numRows == 0 || numCols == 0)
            return;

        std::unordered_set<int> cols;
        std::unordered_set<int> rows;
        
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if(matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for (auto& r : rows) {
            sweepRow(matrix, r);
        }

        for (auto& c : cols) {
            sweepCol(matrix, c);
        }   
    }

    void setZeroConstantSpace(std::vector<std::vector<int>>& matrix) {
        int numRows = matrix.size(), numCols = matrix[0].size();

        if (numRows == 0 || numCols == 0) return;

        bool zeroFirstRow = false, zeroFirstCol = false;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (i == 0) {
                    zeroFirstRow = zeroFirstRow || (matrix[i][j] == 0);
                }

                if (j == 0) {
                    zeroFirstCol = zeroFirstCol || (matrix[i][j] == 0);
                }


                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < numRows; i++) {
            for (int j = 1; j < numCols; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (zeroFirstRow) {
            std::fill(matrix[0].begin(), matrix[0].end(), 0);
        }

        if (zeroFirstCol) {
            for (int i = 0; i < numRows; i++) {
                matrix[i][0] = 0;
            }
        }
    }
}