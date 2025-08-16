/*
Aggresive cows problem 

1. We are given with an array  which give distance between adacent cows now we have k cows we have to arrange them in such a way that the minimum distance between the cows
are maximum

2. means the minimum distance between any two adjacent cows should be maximum 

*/

#include<iostream>
using namespace std;

bool canWePlace(vector<int>nums,int dist,int cows)
{
int count=1;   //  the first cow is placed at the 0th index always which makes our 
int last=nums[0]; 

for(int i=0; i<nums.size(); i++)
{
    if(nums[i]-last>=dist) // if the nums[i]-last >=dist then we can settle the cow there and can just increase the count and update the last 
    {
        count++;
        last=nums[i];
    }

    
}
if(count>=cows) // if this condition stisfies then this dist is possible 
    {
        true;
    }
else
false;

}





int aggressiveCows(vector<int>&stalls,int k)
{
sort(stalls.begin(),stalls.end());

// our placement distance will vary from 1 to max-min and from there we will find the answer 

int n=stalls.size();
int low=1;
int high=stalls[n-1]-stalls[0];  // our max index vary from max-min

while(low<=high)
{
int mid=low+(high-low)/2;
if(canWePlace(stalls,mid,k)==true)
{
    low=mid+1;
}
else
{
    high=mid-1;
}



return high; // you can either return create a variable which will store mid and then return the ans but high pointer will also gives you the answer 

}





}







int main()
{




    return 0;
}