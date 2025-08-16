/*

Number of Provinces 

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

logic is give in the notebook 


*/

/*
Number of Provinces

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected.

Return the total number of provinces.

*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int>& vis)
{
    vis[node] = 1;
    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            dfs(nbr, adj, vis);
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V) // we have been given with a adjacency matrix and we have to figure out adjacency list 
{
    vector<int> adjList[V]; // this is the array of vectors not a single vector 

/*

adjList[0] → vector<int> → empty // now we will start filling elements to it one by one 
adjList[1] → vector<int> → empty
adjList[2] → vector<int> → empty


// in this way we  convert a adj matrix into adj list 
*/




    // Convert adjacency matrix to adjacency list
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j] == 1 && i != j)
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    vector<int> vis(V, 0);  // initialize vis array with size V and all zeros
    int cnt = 0;

    for (int i = 0; i < V; i++) // the number of provinces is equal to number of dfs calls and that is what we have did here 
    {
        if (!vis[i])
        {
            cnt++;
            dfs(i, adjList, vis);
        }
    }

    return cnt;
}

int main()
{
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    int n = isConnected.size();

    int provinces = numProvinces(isConnected, n);

    cout << "Number of Provinces: " << provinces << endl;

    return 0;
}

/*

void DFS(vector<int>&adJList[],vector<int>&vis,int node)
{
    vis[node]=1;

    for(auto nbr:adjList)
    {
        if(!vis[nbr])
        dfs(adjList,vis,node);
    }


}





int numProvinces(vector<vector<int>> adj, int V)

{

vector<int>adjList[V];

for(int i=0; i<V; i++)
{
    for(int j=0; j<V; j++)
    {
        if(ad[i]==adj[j] && i!=j)
        {
            adjList[i].push_back(j);
        }
    }
}

vector<int>vis(V);

for(int i=0; i<; i++)
{
    if(!vis[i])
    {
        cout++;
        dfs(vis,adjList,i);
    }
}








}






*/