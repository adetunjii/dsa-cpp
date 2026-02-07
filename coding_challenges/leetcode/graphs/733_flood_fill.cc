#include <iostream>
#include <vector>

namespace graph {
    void fill(std::vector<std::vector<int>>& image, int sr, int sc, int color, int newColor) {
        if (
            (sr < 0 || sr >= image.size() || 
            sc < 0 || sc >= image[0].size()) || 
            image[sr][sc] != color || image[sr][sc] == newColor
        ) {
            return;
       }

       image[sr][sc] = newColor;

       fill(image,  sr-1, sc, color, newColor);
       fill(image,  sr+1, sc, color, newColor);
       fill(image,  sr, sc-1, color, newColor);
       fill(image,  sr, sc+1, color, newColor);
    }

    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color) {
        fill(image, sr, sc, image[sr][sc], color);
        return image;
    }
}