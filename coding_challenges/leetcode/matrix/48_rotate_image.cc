#include <vector>
#include <ranges>
#include <utility>

void rotate(std::vector<std::vector<int>>& matrix) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    if (numRows == 0 || numCols == 0) return;

    for (int r : std::views::iota(0, numRows)) {
        for (int c : std::views::iota(r+1, numCols)) {
            std::swap(matrix[r][c], matrix[c][r]);
        }
    }

    for (int r : std::views::iota(0, numRows)) {
        std::reverse(matrix[r].begin(), matrix[r].end());
    }
}