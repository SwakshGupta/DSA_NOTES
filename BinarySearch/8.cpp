/*
875. Koko Eating Bananas
Medium
Topics
premium lock icon
Companies
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.




*/

#include<iostream>
using namespace std;

/*so we will find the range of k from where the speed can vary and then we will return our answer for eg- arr[]={3,6,7,11}  max value of k =11 

cuz we have to return min value of k so 11,12,13 will give us same time so 11 min among then hence 11 

1. Now we will find the answer in this range only so we will compute hours for each i and then we will compare that with the hours give if that 
comes out to be lesser than that is going to be the answer 


for(int i=0 -------i=11)
{
    reqtime=fun(nums,i)

    if(reqtime<=h)
    return i;
}

fun(vector<int>nums,int n)
{
    int ans=0;
    
    for(int i=0; i<nums.size(); i++)
    {
        ans+=nums[i]/n // this will return us the time at k speed and then we can get the answer 
    }
}

since we are doing linear search here so we can optimize this code using binary search 

we will check whether mid is possible if yes then we will check for the right side and neglect the left side 

*/


// this function to calculate the max value 

int max(vector<int>&nums)
{
    int maxi=INT_MIN;
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i]>maxi)
        {
            maxi=nums[i];
        }
    }
    return maxi;
}


// this function to calculate the time taken to eat banana at n speed 

long long  count(vector<int>&piles,int n)
{
    long long time=0;

for(int i=0; i<piles.size(); i++)
{
    time+=(piles[i]+n-1)/n;

}


return time;
}




    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int e=max(piles);
        int ans=0;

        // calculate the range of speed from l to e and then we have applied the binary search 

        while(l<=e)
        {
           int mid=l+(e-l)/2;
            long long time=count(piles,mid);

            if(time<=h) //  if time is less then this could be the answer be will further decreae the speed to check for minimum speed
            {
                ans=mid;
                e=mid-1;
            }
            else 
            {
                l=mid+1; // if time taken is greater than we will increase the speed 
            }
        }
        return ans;
    }



int main()
{



    return 0;
}