/*
Check for Bipartite graph 

A graph is bipartite if we can acolor the grpah with two colors such that no two adjacent nodes has the same color 
 





*/








#include<iostream>

using namespace std;

bool dfs(int node,int col,vector<int>adj[],int color[])
{
color[node]=col;


for(auto nbr :adj[node])
{
    if(color[nbr]==-1)
    {
        dfs(node,!col,adj,color);
    }

    else if(color[nbr]==col)
    {
        return false; // if the adjacent node has the same color then return false
    }
}
return true;

}



bool isBipartite(int V,vector<int>adj[])
{

int color[V];
for(int i=0; i<V; i++) // initially we have  given our colored array -1 coloe
{
    color[i]=-1;
}

for(int i=0; i<V; i++)
{
    if(color[i]==-1)
    {
        bool ans=dfs(i,0,adj,color); // if any dfs call return false then return false 

        if(ans==false)
        {
            return false;
        }

    }
}
return true;

}





int main()
{


    return 0;
}