
/*

count subsets with sum K ,  
given an array we have to return number of subsets whose sum is equal to the given sum 

Pretty standared problem 






*/

#include<iostream>
using namespace std;

// reccursive+memorization case 

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


// lets do the tabuation case now 

int solve(vector<int>nums,int index,int target)
{
vector<vector<int>>dp(index,vector<int>(target+1));  // so we are making 2d dp here target+1 ? why

for(int i=0; i<nums.size(); i++)
{
    dp[i][0]=1; // if the target is equal to zero then make that index 1
    
    if(nums[0]>=target)
    dp[i][nums[0]]=1;
}

if(target<0)
return 0;


for(int i=0; i<nums.size(); i++)
{
    for(int j=0; j<=target; j++)
    {   
        int taken=0;
        int notTaken=dp[i-1][j];

        if(nums[i]<target)
        taken=dp[i-1][target-j];

        dp[index][target]=taken+notTaken;
    }
}


}

int main()
{



    return 0;
}