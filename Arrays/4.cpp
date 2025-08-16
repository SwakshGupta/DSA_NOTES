/*
Find the leader in an array leader means that element of array is greatest compare to the all right elements 

[1,5,4,3]

here leader are 5 and 3 since no element is greater than them to the right side 

Intuition

1. We will start from the right side rightmost element will always e the leader and then we will start traversing towards left 

2. if greater element is found then it is going to be leader to all the right elements and then we will update that element 

*/

#include<iostream>
using namespace std;

vector<int>Leader(vector<int>nums)
{
int n=nums.size();
vector<int>ans;

int max=nums[n-1]; // the rightmost element will be the first leader
ans.push_back(nums[n-1]);

for(int i=n-2; i>0; i++)
{
if(nums[i]>max)
{
    ans.push_back(nums[i]);
    max=nums[i];
}
return ans;
}
}



int main()
{

    return 0;
}