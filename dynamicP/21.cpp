/*

72. Edit Distance
Medium
Topics
premium lock icon
Companies
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character


Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')


// so our main purpose is to count number of steps to convert string 2 to string 1 



*/


#include<iostream>
using namespace std;


int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp)
{

if(i<0) return j+1;
if(j<0) return i+1; // these are the base cases 


if(dp[i][j]!=-1)
return dp[i][j];

if(s1[i]==s2[j])
{
    dp[i][j]=solve(i-1,j-1,s1,s2,dp); // if there is a mathing then just move backward 
}
else
{ // we have three cases isertion,deletion or replaecment 


dp[i][j]=1+min(solve(i,j-1,s1,s2,dp),min(solve(i-1,j,s1,s2,dp),solve(i-1,j-1,s1,s2,dp))); // first is insertion,deletion then replacement explanation in the notebook 
}


return dp[i][j];


}







int editDistance(string str1,string str2)
{





}







int main()
{




    return 0;
}

