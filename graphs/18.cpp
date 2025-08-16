/*
Prism Algo to find minimm spanning tree 



*/

#include<iostream>
#include<queue>
using namespace std;

int spanningTree(int v,vector<vector<int>>adj[])  // it is the array of 2d vectores 
{
vector<int>vis(v,0);

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; // it will sort all the nodes according to there wt 

// push the weight and node into the queue
pq.push({0,0});
int sum=0;

while(!pq.empty())
{
    auto it=pq.top(); // the least weight will come at the top 
    pq.pop();

    int wt=it.first;
    int node=it.second;

    if(vis[node]==1)
    continue;

    vis[node]=1;
    sum+=wt;
    for(auto itr:adj[node]) // traversing adjacent nodes  since the least weight auto comes to the top so we dont need to check for the greater and the smaller conditions
    {
        int adjnode=itr[0];
        int dis2=itr[1];

        if(!vis[adjnode])
        {
            pq.push({dis2,adjnode});
        }

    }
  return sum;
}


// in this code i have calculated the minimum weight of the spamming tree  if we want to calculate the whole spamming tree then we have to create a parent vector also 




}




int main()
{





    return 0;
}