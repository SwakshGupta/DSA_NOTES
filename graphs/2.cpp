
// Rotting Oranges 
#include<iostream>
#include<queue>
using namespace std;

/*

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

we will be using bfs here since we require  adjancent orange to be rotted in 1 sec 

*/


int orangesRotten(vector<vector<int>>&grid)
{

    int n=grid.size();   // rows
    int m=grid[0].size(); // columns

    queue<pair<pair<int,int>,int>>q; // two for position if the node(row,column) and last int for time

    vector<vector<int>>vis; // 2d vector to check for the visited nodes

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j]==2) // initially we will put all the rotten oranges into the queue 
            {
                q.push({{i,j},0}); // if the orange is rotten then push that orange into the queue 
                vis[i][j]=2; 
            }
            else
            {
                vis[i][j]=0;
            }
        }
    }
    int time=0;
// here we will define the positions at which a orange rotten other oranges 

int drow[]={-1,0,1,0}; // if we go up then we will do (-1,0) if we go right we will do (0,+1) that is why we have defined these coordinates
int dcol[]={0,1,0,-1};

    while(!q.empty())
    {int r=q.front().first.first; // Finding the row 
     int c=q.front().first.second; // Finding the column 
     int t=q.front().second; // Finding the time
     q.pop();

     for(int i=0; i<4; i++) // here we will traverse across the four nbrs 

    {
       int nrow=r+drow[i]; 
       int ncol=c+dcol[i];

       if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1) // defining that the nbr row or col should not be rotten and should be fresh
       {
         q.push({{nrow,ncol},t+1});
         vis[nrow][ncol]=2; // marked that as visited 
       }
    }

    }
    //  now we have to check were all these fresh oranges were converted into rotten or not 

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(vis[i][j]!=2 && grid[i][j]==1) // if grid still has fresh oranges and they are not visited yet then we will return -1 means they can't be rotten 
            {
                return -1;
            }
        }
    }
    return time;
}



int main()
{




    return 0;
}