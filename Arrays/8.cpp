/*

You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.


Example 1:

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions. 


Approach:

1. Create two seperate array positive and negative array fill them with the poisitve and negative elements
2. Then do one iteration and put all the elements back to the array considering the given conditions

2.............

1.

*/
#include<iostream>
using namespace std;

// this was brute force approach where we are creating two vectors

void solve(vector<int>&nums)
{
    int n=nums.size();
    vector<int>neg;
    vector<int>pos;

for(int i=0; i<n; i++)
{
    if(nums[i]>=0)
    pos.push_back(nums[i]);

    if(nums[i]<0)
    neg.push_back(nums[i]);

}

for(int i=0; i<n/2;i++)
{
nums[2*i]=pos[i];
nums[2*i+1]=neg[i];
}

}

// next appraoch in the notebook
vector<int>Rearrange(vector<int>&nums)
{
 int n=nums.size();

 vector<int>ans(n,0); // creted a array where we will store the element in the even and the odd positions 

 int posIndex=0; 
 int negIndex=1;

 for(int i=0; i<n; i++)
 {

if(nums[i]<0)
{
    ans[negIndex]=nums[i]; // if number is neagtive then set that number in the odd position and then increment the position by 2
    negIndex+=2;  
}
else
{
    ans[posIndex]=nums[i];
    posIndex+=2;
}

return ans;
 }
}


/*
This next function is the special case here the positive and negative elements are not equal  if any positive and negative remains then add 
them at the end without altering the order 
*/ 

vector<int>solve3(vector<int>&nums)
{

 int n=nums.size();
    vector<int>neg;
    vector<int>pos;  // created two vectors and then pushed the respected elements in the array 

for(int i=0; i<n; i++)
{
    if(nums[i]>=0)
    pos.push_back(nums[i]);

    if(nums[i]<0)
    neg.push_back(nums[i]);

}

if(pos.size()>neg.size())
{
for(int i=0; i<neg.size(); i++)

{
nums[2*i]=pos[i];
nums[2*i+1]=neg[i]; // so we have filled the elements where both the negatives and positives were equal 
}

int index=neg.size()*2;

for(int i=neg.size(); i<pos.size(); i++)
{
nums[index]=pos[i];
index++;
}
}

    
}




int main()
{




    return 0;
}



/*
vector<int>Rearrange(vector<int>&nums)
{
int n=nums.size();
vector<int>ans(n,0);

int odd=1;
int even=0;

for(int i=0; i<n; i++)
{
if(nums[i]>0)
{
    ans[even]=nums[i];
    even+=2;
}

if(nums[i]<0)
{
    ans[odd]=nums[i];
    odd+=2;
}

return ans;





}









}












*/