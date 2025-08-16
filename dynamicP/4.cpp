/*
120. Triangle


Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).



here we have fixed starting pointa nd variable ending point 


*/

#include<iostream>
using namespace std;

// this is the tabuation case 

int minimumPathSum(vector<vector<int>>&triangle,int n)
{

vector<vector<int>>dp(n,vector<int>(n,0));

for(int j=0; j<n; j++)
{
    dp[n-1][j]=triangle[n-1][j]; // this is our base case  we are filling the last row of dp with last row of triangle see notes 
}


for(int i=n-2; i>=0; i--)
{
    for(int j=i; j>=0; j--)
    {
        int d=triangle[i][j]+dp[i+1][j]; // here we are calulating for the down move 
        int dg=triangle[i][j]+dp[i+1][j+1]; // here we are calulating for the diagonal move

        dp[i][j]=min(d,dg);
    }
}


return dp[0][0];

}




int main()
{



    return 0;
}