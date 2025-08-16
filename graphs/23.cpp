/*
Articulation Points:
Nodes whose removal increases the number of connected components in the graph.

We will use Tarjan's algorithm to find them.

Steps:
1. Create 4 arrays/vectors:
   - discovery time (`disc`)
   - lowest reachable time (`low`)
   - parent array (`parent`)
   - visited array (`vis`)
2. Use DFS to:
   - Assign discovery & low times.
   - Update low values based on back edges.
   - Check articulation point conditions:
       a) If root node of DFS has 2 or more children → AP.
       b) If non-root node: low[child] >= disc[node] → AP.
3. Store articulation points in `result`.
*/

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
#include <set> // to avoid duplicate articulation points
using namespace std;

// DFS function to find articulation points
void dfs(int node, vector<int> &parent, int &timer, vector<int> &disc, vector<int> &low,
         set<int> &result, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis)
{
    vis[node] = true;
    disc[node] = low[node] = timer++; // assign discovery and low time
    int children = 0; // count children of the node in DFS tree

    for (auto nbr : adj[node]) // loop to traverse through all the neighbors of node
    {
        if (nbr == parent[node]) // if neighbor is the parent, skip
            continue;

        if (!vis[nbr]) // if the neighbor is not visited, call DFS on it
        {
            parent[nbr] = node;
            children++; // this is a child of current node in DFS tree

            dfs(nbr, parent, timer, disc, low, result, adj, vis);

            // while coming back (backtracking), update low[node]
            low[node] = min(low[node], low[nbr]);

            // --- Articulation Point condition for non-root nodes ---
            if (parent[node] != -1 && low[nbr] >= disc[node])
            {
                result.insert(node);
            }
        }
        else
        {
            // Back edge found → update low[node]
            low[node] = min(low[node], disc[nbr]);
        }
    }

    // --- Special case for root node ---
    if (parent[node] == -1 && children > 1)
    {
        result.insert(node);
    }
}

// Function to find all articulation points in a graph
vector<int> findArticulationPoints(vector<vector<int>> &edges, int v, int e)
{
    // Step 1: Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int w = edges[i][1]; // renamed to avoid shadowing 'v'

        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    // Step 2: Initialize required data structures
    int timer = 0;
    vector<int> disc(v, -1);    // discovery times
    vector<int> low(v, -1);     // lowest reachable times
    vector<int> parent(v, -1);  // parent array
    unordered_map<int, bool> vis;
    set<int> result; // to store articulation points without duplicates

    // Step 3: Call DFS for each component
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, timer, disc, low, result, adj, vis);
        }
    }

    // Step 4: Convert set to vector for output
    return vector<int>(result.begin(), result.end());
}

int main()
{
    // Example graph input
    int v = 5; // number of vertices
    int e = 5; // number of edges
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {3, 4}};

    vector<int> articulationPoints = findArticulationPoints(edges, v, e);

    cout << "Articulation Points in the graph:" << endl;
    for (auto ap : articulationPoints)
    {
        cout << ap << endl;
    }

    return 0;
}
