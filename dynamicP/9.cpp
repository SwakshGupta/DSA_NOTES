/*
Count the partition with given Difference  . So we have to count number of subsequence whose difference is equal to the given target

dp-18


*/






#include<iostream>
using namespace std;


// this is the previous code  we will be using that thing in this code 

int solve(vector<int>nums,int index,int target,vector<vector<int>>&dp)
{

if(target==0)
return 1;

if(index==0)
{
    if(target<=nums[0])
    return 1;
}
 
if(dp[index][target]!=-1)
return dp[index][target];

int taken=0;

if(target>nums[index])
{
    taken=solve(nums,index-1,target-nums[index],dp);
}

int notTaken=solve(nums,index-1,target,dp);

dp[index][target]=taken+notTaken;
}











// this question code 

int findWays(vector<int>arr,int tar)
{
    int n=arr.size();

vector<vector<int>>dp(n,vector<int>(tar+1,-1));

 return solve(arr,n,tar,dp);



}






int countPartitions(int n,int d ,vector<int>&arr)
{
int totSum=0;

for(auto nbr:arr)
totSum+=nbr;

if(totSum-d<0 || (totSum-d)%2!=0)
return false;

return findWays(arr,(totSum-d)/2); // so through this we have converted our problem to number of subsets with given target




}


int main()
{




    return 0;
}