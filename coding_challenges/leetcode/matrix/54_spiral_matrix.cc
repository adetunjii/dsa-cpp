#include <vector>
#include <ranges>

namespace matrix {
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix){
        int rowSize = matrix.size(), colSize = matrix[0].size();

        const int MAX = 101;

        if (rowSize == 0 || colSize == 0) {
            return {};
        }

        int sz = rowSize * colSize;
        std::vector<int> res(sz);

        int x = 0, y = 0, dx = 1, dy = 0;

        for (auto i : std::views::iota(0, sz)) {
            res[i] = matrix[y][x];
            matrix[y][x] = MAX;

            if (
                x+dx < 0 || x+dx == colSize ||
                y+dy < 0 || y+dy == rowSize || 
                matrix[y+dy][x+dx] == MAX
            ) {
                int temp = dx;
                dx = -dy;
                dy = temp;
            }

            x += dx;
            y += dy;
        }

        return res;
    }
}