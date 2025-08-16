/*
  Shortest pat in binary matrix     


Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.



// so we will create  a queue and a distance vector we will push the initial element in the queue and then keep traversing the elements till the queue is not empty


*/

#include<iostream>
#include<queue>
using namespace std;

int shortestPath(vector<vector<int>>&grid,pair<int,int>source,pair<int,int>destination)
{
int n=grid.size();
int m=grid[0].size();

vector<pair<int,int>>adj[n];

for(auto it:grid)
{
    adj[0].push_back({it[1],it[2]});
    adj[1].push_back({it[0],it[2]});
}

queue<pair<int,pair<int,int>>>q; // first int is distance and second and third int are row and col of matrix

vector<vector<int>>dist(n,vector<int>(m,1e9));  // initially the distance is set as maximum

dist[source.first][source.second]=0; // the distance of the source is set to be zero 
q.push({0,{source.first,source.second}}); 

int drow[]={-1,0,1,0};
int dcol[]={0,1,0,-1};

while(!q.empty())
{
   int dis=q.front().first;
   int r=q.front().second.first;
   int c=q.front().second.second;
    q.pop();

 for(int i=0; i<4; i++)
 {
    int row=r+drow[i];
    int col=c+dcol[i];

// here we will update our answer 

if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1 && dis+1<dist[row][col] ) // then we need to upgrade the distance array and push this into the queue
{

dist[row][col]=dis+1; // cuz with every row we are traversing we are increasing the distance by  1

// before we will check whther we have reached to the final destination 

if(row==destination.first && col==destination.second ) // if the row and column reach to the final node then return the answer
{
    return dis+1;
}
q.push({1+dis,{row,col}}); // and pusht 




}


 }
    
}







}

int main()
{





    return 0;
}