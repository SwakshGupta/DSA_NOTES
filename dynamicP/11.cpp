/*
Minimum coins on dp:20  (given a target and array of coins we have to return minimum number of coins to achieve that target )




*/

#include<iostream>
using namespace std;

// here we wil write the memorization 

int f(int ind,int T,vector<int>nums,vector<vector<int>>dp)
{

// base case 
if(ind==0)
{
    if(T%nums[ind]==0) // if the target is divisible by nums[indices] then return t/nums[ind];
    {
        return T/nums[ind]; 
    }
    else
    return 1e9;
}

if(dp[ind][T]!=-1)
return dp[ind][T];

int taken=0;

if(T>=nums[ind])
{
  taken=f(ind,T-nums[ind],nums,dp)+1;  // this is the taken case if a coin is taken then size would increase by 1
}

int notTaken=f(ind-1,T,nums,dp); // if coin is not taken then we will just  decrease the index number 

return dp[ind][T]=min(taken,notTaken);


}



// here is the tabulation case 

int solve(int ind,int T,vector<int>nums)
{
int n=nums.size();

vector<vector<int>>dp(n,vector<int>(T+1,-1)); // created a dp with size n,T+1

// base conidtion 

for(int i=0; i<T; i++) // we are filling the first row from target(0-T)
{
    if(i%nums[0]==0) // this base condition is similar to memorzation case if the index is zero then we check the modulo with the target and then fill that index 
    {
    dp[0][i]=i/nums[0];
    }
    else
    {
       dp[0][i]=1e9;  // if modulo is not equal to zero then we will just give intmax;
    }
}

for(int i=1; i<=ind; i++)
{
    for(int j=0; j<T; j++)
    {
     int taken=0;
     if(j>=nums[i])
     {
        taken=dp[i][j-nums[i]]+1;
     }
     int notTaken=dp[i-1][j];

     dp[i][j]=min(taken,notTaken);
    }
}

return dp[ind][T];

}


int main()
{




    return 0;
}