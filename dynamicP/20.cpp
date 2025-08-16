/*

Distict subsequence problem 

so we have two stings str1 and str2 so we will find number of subsequence in str1 which will match to str2


*/




#include<iostream>
using namespace std;

// This is the reccursive solution 


int f(int i,int j,string s,string t)
{

if(j<0) return 1;
if(i<0) return 0; // these are the base conditions 


if(s[i]==t[j])
{
    return f(i-1,j-1,s,t)+f(i-1,j,s,t);
}
else
{
    return f(i-1,j,s,t);
}



}


// lets do the memo solution 


int solve(int i,int j,string s,string t,vector<vector<int>>dp)

{

if(j<0) return 1;
if(i<0) return 0; // these are the base conditions 


if(dp[i][j]!=-1)
return dp[i][j];


if(s[i]==t[j])
{
  return   dp[i][j]= solve(i-1,j-1,s,t,dp)+solve(i-1,j,s,t,dp);
}
else
{
    return dp[i][j]=solve(i-1,j,s,t,dp);
}



}


// so to remove the stack space we will do the tabulation 

// for tabulation we will do the right shifting by 1 first 


int solve2(int i,int j,string s,string t)
{

    int n=s.size();
    int m=s.size();


    vector<vector<int>>dp(n+1,vector<int>(m+1,-1)); // since we have done right shifting by one so in order ot componsate that we will do this 


    for(int i=0; i<n; i++)
    {
        dp[i][0]=1; // if the j=0 for any of the i then we will return 1 
    }

    for(int j=0; i<m; j++)
    {
        dp[0][j]=0; // if i=0 for an vlaue of j then we will return 0 there 
    }



for(int i=1; i<n; i++)
{
    for(int j=1; j<m; j++)
    {
        if(s[i-1]==t[j-1])
        {
            return dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
        else
        {
            return dp[i][j]=dp[i-1][j];
        }
    }
}





}

// optimized solution in striver video dp-32 distict subsequence 





int numDistict(string s,string t)
{
    int n=s.size();
    int m=t.size();

    vector<vector<int>>dp(n,vector<int>(m,-1));

    solve(n-1,m-1,s,t,dp);


}



int main()
{




    return 0;
}