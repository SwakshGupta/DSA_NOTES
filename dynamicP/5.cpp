/*

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either 
directly below or diagonally left/right. Specifically, 
the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).


Here we have variable starting point and variable ending point before we had

1. Fixed starting point and Fixed ending point 
2. Fixed starting point and variable ending point 
*/

#include<iostream>
using namespace std; 

// this is the memorization case 

int f(int i,int j,vector<vector<int>>matrix,vector<vector<int>>dp)
{

if(j<0 || j>matrix.size())
{
    return -1e9;
}

if(i==0)
return matrix[0][j];

if(dp[i][j]!=-1)
return dp[i][j];


int u=matrix[i][j]+f(i-1,j,matrix,dp);
int ld=matrix[i][j]+f(i-1,j-1,matrix,dp); // left diagonal 
int rd=matrix[i][j]+f(i-1,j+1,matrix,dp); // right diagonal

return dp[i][j]=max(u,ld,rd);
}

// this is the tabulation case


int f1(int i,int j,vector<vector<int>>matrix)
{

    int n=matrix.size();
    int m=matrix[0].size();

vector<vector<int>>dp(n,vector<int>(m));

if(j<0 || j>matrix[0].size())
return -1e9;

for(int j=0; j<m; j++)
{
  dp[0][j]=matrix[0][j];
}


// now lets cover all the cases 

for(int i=1; i<n; i++)
{
    for(int j=0; j<n; j++)
    {
        int d=matrix[i][j]+dp[i+1][j];
        int ld=matrix[i][j]+dp[i+1][j-1];
        int rd=matrix[i][j]+dp[i+1][j+1];

        dp[i][j]=max(d,ld,rd);
    }
}
return dp[n][m];


}





int getMaxPathSum(vector<vector<int>>&matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();

    int maxi=-1e9;

    vector<vector<int>>dp(n,vector<int>(m,-1));

    for(int j=0; j<m; j++)
    {
        maxi=max(maxi,f(n-1,j,matrix,dp));
    }



}



int main()
{




    return 0;
}