/*

DP on grid


62. Unique Paths
Solved
Medium
Topics
premium lock icon
Companies
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the 
bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 10


here we have fixed starting points and fixed ending points 

*/

#include<iostream>
using namespace std;



// this is memorization method to find unique paths 

int solve(int m,int n,vector<vector<int>>&dp)
{
if(m<0 || n<0)
{
    return 0;
}

if(m==0 && n==0)
{
    return 1;
}

if(dp[m][n]!=-1)
{
    return dp[m][n];
}

int down=solve(m-1,n,dp);
int right=solve(m,n-1,dp);

return dp[m][n]=down+right;

}


// lets do the tabulation here 

int solve2(int m,int n)
{
vector<vector<int>>dp(m,vector<int>(n,-1));

dp[0][0]=1;

// now we will traverse across the rows and columns 

for(int i=0; i<m; i++)
{
    for(int j=0; j<n; j++)
    {    
        
        int up=dp[i-1][j];
        int left=dp[i][j-1];

        dp[i][j]=up+left;
    }
}

return dp[m][n];




}

// if there is a previous row and previous colmn then we can space optimize it





  
int main()
{

int m;
int n;
    
vector<vector<int>>dp(m,vector<int>(n,-1));
      

return solve(m-1,n-1,dp);
   




    return 0;
}