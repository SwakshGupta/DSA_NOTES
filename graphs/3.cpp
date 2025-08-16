/*
Distance of nearest cell having 1

Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are 
the row number and column number of the nearest cell having value 1. There should be atleast one 1 in the grid.


// the code is similar to previous one 


*/




#include<iostream>
#include<queue>
using namespace std;

vector<vector<int>>nearest(vector<vector<int>>grid)
{
int n=grid.size();
int m=grid[0].size();
queue<pair<pair<int,int>,int>>q;
vector<vector<int>>vis(n,vector<int>(m,0));
vector<vector<int>>dis(n,vector<int>(m,0));

for(int i=0; i<n; i++)
{
    for(int j=0; j<m; j++)
    {
        if(grid[i][j]==1) // if any grid has 1 on them then push them into the queue and mark visited =1
        {
            q.push({{i,j},0});
            vis[i][j]=1;

        }
        else
        {
            vis[i][j]=0; // if there is no cell 1 in the grid then mark visited as 0
        }
    }
}




int drow[]={-1,0,1,0}; // if we go up then we will do (-1,0) if we go right we will do (0,+1) that is why we have defined these coordinates
int dcol[]={0,1,0,-1};

while(!q.empty())
{
int r=q.front().first.first;
int c=q.front().first.second;
int distance=q.front().second;


for(int i=0; i<4; i++)
{
int nrow=r+drow[i];
int ncol=c+dcol[i];

if(nrow>0 && nrow<=n && ncol>0 && ncol<=m && vis[nrow][ncol]==0 && grid[nrow][ncol]==0) // if all these conditions satisfies then we can mark grid as 1 
{
    grid[nrow][ncol]=1;
    vis[nrow][ncol]=1;
    dis[nrow][ncol]=distance;

    q.push({{nrow,ncol},distance+1}); // while pushing into the queue we are increasing the distance at the same time 
}
}

}
return dis;


}

int main()
{




    return 0;
}