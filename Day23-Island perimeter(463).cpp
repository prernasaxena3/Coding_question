//Question - 463 - leetcode - Island Perimeter

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int islandPerimeter(const vector<vector<int>>& grid) {
        int perimeter = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                // Check if the current cell is land (1)
                if (grid[i][j] == 1) {
                    // Efficiently calculate perimeter using neighbors
                    perimeter += countLandPerimeter(grid, i, j);
                }
            }
        }

        return perimeter;
    }

private:
    int countLandPerimeter(const vector<vector<int>>& grid, int i, int j) {
        int localPerimeter = 0;

        // Check all four neighbors (up, down, left, right)
        if (i - 1 < 0 || grid[i - 1][j] == 0) {  // Out of bounds or water (0)
            localPerimeter++;
        }
        if (i + 1 >= grid.size() || grid[i + 1][j] == 0) {  // Out of bounds or water (0)
            localPerimeter++;
        }
        if (j - 1 < 0 || grid[i][j - 1] == 0) {  // Out of bounds or water (0)
            localPerimeter++;
        }
        if (j + 1 >= grid[i].size() || grid[i][j + 1] == 0) {  // Out of bounds or water (0)
            localPerimeter++;
        }

        return localPerimeter;
    }
};
