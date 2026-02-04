// LeetCode 0200. Number of Islands
// https://leetcode.com/problems/number-of-islands/
//
// Tags: Array, Depth-First Search, Breadth-First Search, Union Find, Matrix
//
// Problem:
//     Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
//     An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
//     Example 1:
//     Input: grid = [
//       ["1","1","1","1","0"],
//       ["1","1","0","1","0"],
//       ["1","1","0","0","0"],
//       ["0","0","0","0","0"]
//     ]
//     Output: 1
//
//     Example 2:
//     Input: grid = [
//       ["1","1","0","0","0"],
//       ["1","1","0","0","0"],
//       ["0","0","1","0","0"],
//       ["0","0","0","1","1"]
//     ]
//     Output: 3
//
//     Constraints:
//     - m == grid.length
//     - n == grid[i].length
//     - 1 <= m, n <= 300
//     - grid[i][j] is '0' or '1'.
//
// Solution:
//     - [To be implemented]
//
// Time Complexity: O(?)
//     - [To be analyzed]
//
// Space Complexity: O(?)
//     - [To be analyzed]
//
// Pitfalls:
//     - [To be identified]

#pragma once

#include <vector>

namespace leetcode {

class UnionFind {
public:
    std::vector<int> parent;
    std::vector<int> rank;
    int count;

    UnionFind(int size): parent(size), rank(size, 0), count(0) {
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent) {
            return;
        }

        // If ranks are different, attach smaller rank tree under root of higher rank tree
        // This is for balancing the tree and keeping it flat, so that find operations are faster
        if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else {
            // If ranks are the same, then make one as root and increment its rank by one
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }

        --count;
    }

    int getCount() const {
        return count;
    }

};

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int row = grid.size();
        if (row == 0) {
            return 0;
        }
        int col = grid[0].size();
        int size = row * col;
        UnionFind uf(size);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                // Only process land cells
                if (grid[i][j] != '1') {
                    continue;
                }
                
                uf.count++;
                // Convert 2D index to 1D index
                int id = i * col + j;
                // Check right and down neighbors
                // No need to check left and up neighbors as they would have been processed already
                std::vector<std::vector<int>> directions = {{0, 1}, {1, 0}};
                for (auto& direction : directions) {
                    int ni = i + direction[0];
                    int nj = j + direction[1];
                    if (ni < row && nj < col && grid[ni][nj] == '1') {
                        int neighbor_id = ni * col + nj;
                        uf.unite(id, neighbor_id);
                    }
                }
            }
        }
        return uf.getCount();
    }
};

}  // namespace leetcode