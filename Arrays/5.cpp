/*
Longest consecutive sequence 

So we are given the array of integers and we have to find longest consecutive integer

approach1 :

1. sort the array (writen in the notes )

Example 1:

Input: [100, 200, 1, 3, 2, 4]

Output: 4

Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.



*/

#include<iostream>
using namespace std;

// we are sorting the array in this problem and also we are distorting the array 

int longestSubarray(vector<int>nums)
{

if(nums.size()==0) 
return 0;

sort(nums.begin(),nums.end());

int n=nums.size();
int lastSmaller=INT_MIN;
int count=0;
int longest=1;

for(int i=0; i<n; i++)
{

    if(nums[i]-1==lastSmaller)
    {
        count++;
        lastSmaller=nums[i];
    }
    else if(nums[i]!=lastSmaller)
    {
      count=1;
      lastSmaller=nums[i];
    }
    longest=max(longest,count);
}

return longest;


}

/*
This is hte optimal approach 



*/

int main()
{




    return 0;
}

/*

int longestSubarray(vector<int>nums)
{
int lastSmaller=nums[0];
int n=nums.size();
int maxi=0;
int count=0;


for(int i=1; i<n; i++)
{
    

if(nums[i]-1==lastSmaller)
{
    count++;
    lastSmaller=nums[i];

}

else if(nums[i]!=lastSmaller)
{
    count=1;
    lastSmaller

}

maxi=max(maxi,count);






}







}







*/