/*
Maximum Product subarray 

Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.



*/




#include<iostream>
using namespace std;

int maxProduct(vector<int>nums)
{
int suffix=1;
int prefix=1;
int maxProduct=0;
int n=nums.size();

if(n==1)
{
    return nums[0]; // if only one elementn is there then reutrn that element only 
}


for(int i=0; i<nums.size(); i++)
{

if(prefix==0)  // we prefix is becoming zero anywhere there we are reseting it to one 
prefix=1;

if(suffix==0)
suffix=1;


prefix*=nums[i];  // multiplyinh the predix with num[i] and suffix with nums[n-i-1]
suffix*=nums[n-i-1];

maxProduct=max(maxProduct,max(suffix,prefix));
}
return maxProduct;



}

int main()
{




    return 0;
}