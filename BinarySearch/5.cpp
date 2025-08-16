/*
Find the minimum in rotated sorted array 

1. Here again we will figure out the sorted part we will  find the minimum there and then trim that part 

2. Then we will explore the other half of the array  



so we are first doing the first half of the array  find the minimum array and then we will do the second half of the array 



*/

#include<iostream>
using namespace std;


int findMin(vector<int>&arr)
{

int low=0;
int high=arr.size()-1;
int ans=INT_MAX;

while(low<=high)
{
    int mid=low+(high-low)/2;

    if(arr[low]<=arr[high]) // means the array was sorted end to end 
    {
        ans=min(ans,arr[low]); // if the left part is sorted then the leftmost part is smallest
        break;
    }

if(arr[low]<=arr[mid]) // means the first half is sorted 
{
    ans=min(ans,arr[low]);
    low=mid+1;
}


else // second half is sorted 
{
    high=mid-1;
    ans=min(ans,arr[mid]);
}
}
return ans;
}





int main()
{




    return 0;
}