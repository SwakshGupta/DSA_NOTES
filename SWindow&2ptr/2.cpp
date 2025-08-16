/*
Max Consecutive Ones III

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.


Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.


*/


#include<iostream>
using namespace std;

int countOne(vector<int>nums,int k)
{
int zeroCnt=0;
int l=0;
int r=0;
int n=nums.size();
int maxi=0;

while(r<n)
{
    if(nums[r]==0)
    {
        zeroCnt++;
    }

    while(zeroCnt>k)
    {
        if(nums[l]==0)
        {
            zeroCnt--;
        }
        l++;
    }
    int len=r-l+1;
    maxi=max(maxi,len);

    r++;
}
return maxi;
}

// more optimized approach in striver lecture watch that lecture since the concept is also used in other question to find optimized answer 

// more optimized approach  the time complexity for  previous part was O(2N) watch that from striver lecture and write it down later 




int main()
{




    return 0;
}