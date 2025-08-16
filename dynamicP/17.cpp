/*
Minimum insertions require to make a string a palindrome 

number of insertions=n-longest palindromic subsequence


*/

#include<iostream>
using namespace std;

// previous code 

int LCS(string s,string t)
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

int longestPalindrome(string s)
{

string t=s;

reverse(t.begin(),t.end()); 

return LCS(s,t); // passed the original and reverse string and yep we are done 
}



// here is the code to this problem

int minInsertion(string str)
{
    return str.size()-longestPalindrome(str); 
}








int main()
{




    return 0;
}