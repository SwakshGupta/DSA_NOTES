/*
Surrounded X problem  question in 

You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

*/


#include<iostream>
using namespace std;


// here we will be doing the dfs call

void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&mat,int delrow[],int delcol[])
{

vis[row][col]=1; // now since we have visited thsi thing we will check for all four direction 
int n=mat.size();
int m=mat[0].size();

// traversing across all four directions

for(int i=0; i<4; i++)
{
    int nrow=row+delrow[i];
    int ncol=col+delcol[i];
if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='0') // call dfs if the adjacent element is 0 connected to the zero edge can be visited 
{
    dfs(nrow,ncol,vis,mat,delrow,delcol);
}

}

}


vector<vector<char>>fill(int n,int m,vector<vector<char>>mat)
{

vector<vector<int>>vis(n,vector<int>(m,0));

// traverse the first row and the last row

// we will traverse first row last row first column and last column and call dfs for all the nodes so that all the 

int delrow[]={-1,0,1,0};
int delcol[]={0,1,0,-1};


for(int j=0; j<m; j++)
{
     // first row 
    if(!vis[0][j] && mat[0][j]=='0')
    {
     dfs(0,j,vis,mat,delrow,delcol); // call the dfs if zero lies in the first row 
    }

    // last row
    if(!vis[n-1][j] && mat[n-1][j]=='0') // if the last row has zero in it then we will do dfs
    {
        dfs(n-1,j,vis,mat,delrow,delcol);
    }
}

// now we will do the same for the first column and the last column

for(int i=0; i<n; i++)
{
    // first column
    if(!vis[i][0] && mat[i][0]=='0')
    {
        dfs(i,0,vis,mat,delrow,delcol);
    }
    // last column 

    if(!vis[i][m-1] && mat[i][m-1]=='0')
    {
        dfs(i,m-1,vis,mat,delrow,delcol);
    }
}

for(int i=0; i<n;i++)
{
    for(int j=0; j<m; j++)
    {
        if(!vis[i][j] && mat[i][j]=='0') // if that cell is not visited and we  have zero in the matrix then we will mark that matrix to X 
        {
            mat[i][j]='X'; 
        }
    }
}




}





int main()
{





    return 0;
}