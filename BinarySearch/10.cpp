/*
1283. Find the Smallest Divisor Given a Threshold
Medium
Topics
premium lock icon
Companies
Hint
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.



*/

#include<iostream>
using namespace std;



int findmax(vector<int>nums)
{
    int ans=INT_MIN;
for(int i=0; i<nums.size(); i++)
{
    if(ans<nums[i])
    {
        ans=nums[i];
    }
}
return ans;
}


int f(vector<int>&nums,int mid)
{
int count=0;

for(int i=0; i<nums.size(); i++)
{
    count+=(nums[i]+mid-1)/mid; //  this is the ceiling division this rounds up to the nearest integer 
}

return count;

}

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        int ans=0;

        int l=1;
        int h=findmax(nums);

        while(l<=h)
        {
            int mid=l+(h-l)/2;
            count=f(nums,mid); // checking whether the mid element is smaller than that 

            if(count<=threshold)
            {
             ans=mid;
              h=mid-1;
            }
            else
            {
                l=mid+1;
            }
                    }
        return ans;
    }
int main()
{




    return 0;
}