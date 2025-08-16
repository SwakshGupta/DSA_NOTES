/*
DP on subsequences 

return the subsequence which gives us the sum equal to k


// typical include and exclude problem 


*/

#include<iostream>
using namespace std;


bool solve(vector<int>nums,vector<vector<int>>dp,int target,int index)
{

if(target==0)
return true;

if(index==0)
return (target==nums[0]); // if target equalt to the zero index nums then retrn true

if(dp[index][target]!=false)
return true;

bool include=false;

if(target>nums[index])
{
     include=solve(nums,dp,target-nums[index],index+1);
}

int exclude=solve(nums,dp,target-nums[index],index+1);

dp[index][target]=include || exclude;

}


int main()
{




    return 0;
}