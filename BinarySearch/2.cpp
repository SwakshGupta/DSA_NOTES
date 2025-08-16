/*
Lower bound and upper bound problems 




*/

#include<iostream>
using namespace std;

int lowerBound(vector<int>nums,int target,int n)
{

int low=0;
int high=n-1; 
int ans=n; // initially we have put the index at the hypotheical index just in case if the LB is not found 

int mid=low+(high-low)/2;


while(low<=high)
{
    if(nums[mid]>=target)
    {
        ans=mid;   // this could be the answer 
        high=mid-1;
    }
    else
    {
        low=mid+1;
    }

}

return ans;


}



// in contest we can write teh lower bound like this 

/*
lb=lower_bound(arr.begin(),ar.end(),n)- arr.begin(); 
*/


int upperBound(vector<int>nums,int target,int n)
{

int low=0;
int high=n-1; 
int ans=n; // initially we have put the index at the hypotheical index just in case if the LB is not found 

int mid=low+(high-low)/2;


while(low<=high)
{
    if(nums[mid]>target) // this is the only difference instead of >= sign we are doing the > sign only
    {
        ans=mid;   // this could be the answer 
        high=mid-1;
    }
    else
    {
        low=mid+1;
    }

}

return ans;


}


int main()
{
  



    return 0;
}