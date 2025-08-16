/*
Print Shortest common supersequence so we are given with two strings and we have to return shortest sequence from which these two strings can be derived 




// agian we will be using the LCS here

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

       else dp[i][j]=max(dp[i-1][j],dp[i][j-1]); 
    }
}

// so we have created the dp via the LCS code 

string ans="";
int i=n;
int j=m;

while(i>0 && j>0)
{
    if(s[i-1]==t[j-1]) // if character in both the strings are equal then we just push that element and then move diagonally
    {
        ans+=s[i-1];
        i--;
        j--;
    }

    else if(dp[i-1][j]>dp[i][j-1]) // if the upper word is greater then we move up and at the same time we will push the element from where we have moved 
    {
        ans+=s[i-1];
        i--;
    }

    else if(dp[i][j-1]>dp[i-1][j])
    {
        ans+=t[j-1]; // horizontal momets then we will push that element from where we have moved
        j--;
    }
}

while(i>0) // if the stirng is still remaining then we will those things into our answer
{
    ans+=s[i-1];
    i--;
}

while(j>0)
{
    ans+=s[j-1];
    j--;
}







}







int main()
{




    return 0;
}