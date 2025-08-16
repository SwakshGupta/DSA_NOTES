/*
Rod cutting problem 

so we are given a rod, and a array which has value according to the length of the rod so we have to cut the rod in such a way that we get the max profit  



its simple taken and not taken problem 


*/

#include<iostream>
using namespace std;

// reccursive case

int f(int ind,int N,vector<int>&prices)
{

if(ind==0)
return N*prices[0];

int notTaken=f(ind-1,N,prices);

int taken=INT_MIN;
int rodLength=ind+1;

if(rodLength<=N)
{
    taken=f(ind,N,prices)+prices[ind];
}

return max(taken,notTaken);




}



// lets do the tabuation 

int solve(int ind,int N,vector<int>prices)
{

int n=prices.size();

vector<vector<int>>dp(n,vector<int>(N+1));

for(int i=0; i<=N; i++)
{
  dp[0][i]=i*prices[0];
}

// lets do the iteraton here 

for(int i=1; i<ind; i++)
{
    for(int j=0; j<ind; j++)
    {
        // write the taken and nottaken cases or just watch striver
    }
}



}



int main()
{




    return 0;
}