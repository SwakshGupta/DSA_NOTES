/*

 Print Longest Common substring


// we will take the longest subsequence code and will do one change in that if (not match then) dp[i][j]=0;


*/

#include<iostream>
using namespace std;

int solve(string s,string t)
{

int n=s.size();
int m=t.size();

vector<vector<int>>dp(n+1,vector<int>(m+1,-1)); // n+1,m+1 why cuz we have  right shifted our indices

// base condition 

for(int i=0; i<=n; i++) // if  index of string become zero then return zero 
dp[i][0]=0; 

for(int j=0;j<=m; j++)
dp[0][j]=0;

for(int i=1; i<=n; i++)
{
    for(int j=1; j<=m; j++)
    {
        if(s[i-1]==t[j-1])
        {
            dp[i][j]=1+dp[i-1][j-1]; // if indices are equal
        }

       else dp[i][j]=0; // this is the only change in case of substring if the dp does not match then we reset it to zero 
    }
}



}





int main()
{




    return 0;
}