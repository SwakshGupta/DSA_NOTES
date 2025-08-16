
/*

in this question we have to print the shortest path in a binary via dijkastras algo we can find the  value of shortest path
  
*/

#include<iostream>
#include<queue>
using namespace std;

vector<int>shortestPath(int n,int m, vector<vector<int>>&edges)
{

vector<pair<int,int>>adj[n+1]; // this is arrays of vector (with node,wt as pairs)

for(auto it:edges)
{
  adj[it[0]].push_back({it[1],it[2]}); 
  adj[it[1]].push_back({it[0],it[2]});
}

priority_queue<pair<int,int>>q;
vector<int>dis(n+1,1e9); // created the distance vector and initiallized with a maximnum value 

vector<int>parent(n+1);

for(int i=0; i<n+1; i++)
{
  parent[i]=i; // initialy every node is its own parent 
}
dis[1]=0;


// here we will do the standared thing of  poping element of queue and then checking its nbrs and than updating the distance if there is any to update 

while(!q.empty())
{
auto it=q.top();    // taken out the top elements of priority queue 
int node=it.second;
int dist=it.first;
q.pop();

for(auto nbr:adj[node]) // traversing across all the neighbouring node 
{ 
int n=nbr.first;
int d=nbr.second;

if(d+dist<dis[n]) // if the distance comes out to be lesser than the distance stored than just update the distance andn push that into the queue
{
  dis[n]=d+dist;
  q.push({d+dist,n});
  parent[n]=node;
}
}
}
// now our parent and distance array is done so we will create ans array out of it 

if(dis[n]==1e9)
return {-1};

vector<int>path;
int node=n;
while(parent[node]!=node) // if node is not its own parent then 
{
  path.push_back(node);
  node=parent[node];
}
path.push_back(1); // in the end we have to push the 1 

reverse(path.begin(),path.end()); // at the end we have to reverse the path and t

return path;

}

int main()
{





    return 0;
}