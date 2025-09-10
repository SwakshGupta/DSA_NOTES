/*

DP on string 

Return the longest common subsequence between the two sequences 


1. Approach is given in the notebook 

2. we will do it via recursion by changing the indices of the reccursion if(str[id1]==str[id2]) then 1+f(id1-1,id2-1) 

3. if the indices does not match then we decrease inx of one string for one function and for other function we decrease the indx of other function and then calculate the max out of it 


simple hai 2 cases are possible  when string are equal and string are not equal when they are equal then we 
will add 1 in the function and when not equal we will find max among the two string 



// most important topic will be used in next videos 

*/


#include<iostream>
using namespace std;


// memorization 

int f(int i,int j, string &s,string &t,vector<vector<int>>dp) // dp has size of indices of both the strings 
{
// base cases 

if(i<0 || j<0)
return 0;

if(dp[i][j]!=-1)
return dp[i][j];


if(s[i]==t[j])
return dp[i][j]=1+f(i-1,j-1,s,t,dp); // if equal then just decrease the index by 1 and increase that thing 

return dp[i][j]=max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp)); // if indices are not equal then return the max (when we have decreased the indices by 1 )





}


// tabulation (there is a slight change in this we have done the shifting of indices means we have shifted the index right by 1 to make the base condition i==0 return 0)


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

return dp[n][m];

}



int main()
{




    return 0;
}