
/*

Minimum number of deletion or insertions to convert string a to string b 


here we will again use longest conmmon subsequence 13.cpp

*/


#include<iostream>
using namespace std;

// this is previous code to find the largest common susting 

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

       else dp[i][j]=max(dp[i-1][j],dp[i][j-1]); // if the indices are not equal
    }
}



}




int minOper(string p,string q)
{
int n=p.size();
int m=q.size();

int minOperations=n+m-2*solve(p,q);

return minOperations;

}




int main()
{




    return 0;
}