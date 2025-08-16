/*
Number of islands part 2





*/

#include <iostream>
#include<unordered_set>
using namespace std;

class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n * n);

        // Directions: up, right, down, left
        vector<pair<int, int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};

        // Step 1: Union all 1's
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    int node = r * n + c; // to caculate a perticular node we do (col*row which has been visited)+column number

                    for (auto [dr, dc] : dirs) {
                        int nr = r + dr, nc = c + dc;
                        if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 1) { 
                            int adjNode = nr * n + nc;
                            dsu.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }

        // Step 2: Find largest island without flipping
        int maxIsland = 0;
        for (int i = 0; i < n * n; i++) {
            if (dsu.findParent(i) == i) {
                maxIsland = max(maxIsland, dsu.size[i]);
            }
        }

        // Step 3: Try flipping each 0
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    unordered_set<int> uniqueParents;
                    for (auto [dr, dc] : dirs) {
                        int nr = r + dr, nc = c + dc;
                        if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 1) {
                            uniqueParents.insert(dsu.findParent(nr * n + nc));
                        }
                    }
                    int newSize = 1; // flipping current 0
                    for (int p : uniqueParents) {
                        newSize += dsu.size[p];
                    }
                    maxIsland = max(maxIsland, newSize);
                }
            }
        }

        return maxIsland;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1, 0},
        {0, 1}
    };
    cout << sol.largestIsland(grid) << endl; // Output: 3
}
