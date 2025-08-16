/*
162. Find Peak Element

A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, 
return the index to any of the peaks.

consider the index -1,n+1 as (-infinity)

1. Solve the problem with (logN) time complexity 



*/

#include<iostream>
using namespace std;

int peak(vector<int>nums)
{
int n=nums.size();
if(n==1)
return 0; // if there is only one element then that is going to be peak since 0,n  index are -infinity

if(nums[0]>nums[1])
return 0; // if 0 index number is greater than the 1 index number then 0th index is a preak element

if(nums[n-1]>nums[n-2])
return n-1; // then n-1 is the peak index;

// these were the edge cases and i have to write the code for 1 and last element by myself  and now i will do the binary search for the remaining elements

int l=1;
int h=n-2;

while(l<=h)
{

int mid=(l+h)/2;

if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])  // this means mid is our peak element
return mid;

else if(nums[mid]>nums[mid-1]) // it means the left side is decreasing and peak element never lies on decreasing curve 
l=mid+1;

else if(nums[mid]>nums[mid+1]) // then right side is decresing and mid never lie on the right side 
h=mid-1;
}

return -1;

}




int main()
{




    return 0;
}