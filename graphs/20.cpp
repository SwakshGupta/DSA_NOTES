/*

Disjoint sets union
*/
#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) { // this function will make all the nodes disoint by making themselves there own parent 
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]); // Path compression
    }

    void unionByRank(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) { 
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int makeConnected(int n, vector<vector<int>>& connections) {
    DisjointSet ds(n);
    int extraEdges = 0;

    for (auto it : connections) {
        int u = it[0];
        int v = it[1];

        if (ds.findParent(u) == ds.findParent(v)) { // if they both have same ultimate parent then that is an extra edge
            extraEdges++; // Already connected — this is an extra edge
        } else {
            ds.unionByRank(u, v);
        }
    }

    int components = 0;
    for (int i = 0; i < n; i++) {
        if (ds.findParent(i) == i) { // if they are there own parents then that is a unique component 
            components++;  
        }
    }

    int requiredEdges = components - 1;
    return (extraEdges >= requiredEdges) ? requiredEdges : -1; // if extraEdges>=requiredEdges then the answer is required edges 
}

int main() {
    int n = 6;
    vector<vector<int>> connections = {
        {0, 1}, {0, 2}, {0, 3}, {1, 4}
        // We need to connect 5 to the rest — one cable is missing
    };

    int result = makeConnected(n, connections);
    cout << "Minimum operations required: " << result << endl;

    return 0;
}
