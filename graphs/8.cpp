/*
Detecting cycle in graph 

1. If we are not able to generte a topo sort then there exist a cycle in the graph 

means if topo sequence size is not equal to the size of graph then we are not able to generate a topo sort


we had copy pasted the whole code only one change is there 
*/

#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;
bool topologicalSort(vector<vector<int>>&edges,int v,int e)
{
    // create the adj list
    unordered_map<int,list<int> >adj;
    int n=edges.size();

    int count=0; // this is the counter of elemetsn in the topo sort 

    for(int i=0; i<e; i++)
    {
        int u=edges[i][0];
        int v=edges[i] [1];

        adj[u].push_back(v);
    }

    // find all the indegrees

    vector<int>indegree(v);
    for(auto i:adj)
    {
        for(auto j:i.second) //  j=i.second (all the nodes adjacent to i)
        {
            indegree[j]++; // increase the indegree ot j
        }
    }
// now 0 indegree valo ko queue mai push kar do 
queue<int>q;
for(int i=0; i<v; i++)
{
    if(indegree[i]==0)
    {
        q.push(i); // pushed the root node into the queue since it has indegree equal to  0
    }
}
// now do BFS
vector<int>ans;
while(!q.empty())
{
    int front=q.front();
    q.pop();
    ans.push_back(front);
    count++;
    

// here we update the indegree
for(auto neighbour:adj[front])
{
    indegree[neighbour]--;  // so we will decrease the indegree of the neighbour 
    if(indegree[neighbour]==0) // if the indegree of nbd is equal to zero then we will push the neightbour 
    {
        q.push(neighbour);
    }
}

}
if(count==v) return false; // if size equal to vertices then it does not have a cycle 

return true; // otherwise it does have a cycle 



}



int main()
{




    return 0;
}