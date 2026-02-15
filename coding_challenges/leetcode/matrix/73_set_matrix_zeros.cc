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
}