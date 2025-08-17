/*

Search in a sorted rotated array 

1. Since it was sorted array and we have to do searc in this so we will do binary search 


1. First figure out which part is sorted by  check whether nums[low]<=nums[mid] which will tell us left part is sorted
and then check for the right part which will tell us whether the right part is sorted 

2.  and then just check whether the left part lie or not 

*/

#include<iostream>
using namespace std;

int search(vector<int>&arr,int n,int k)
{

int low=0;
int high=n-1;

while(low<=high)
{

int mid=low+(high-low)/2;

if(arr[mid]==k)
return mid;

// till here we have done the binary search but now we will start checking which part is sorted is it the left half  or the right half


// if the left half is sorted 

if(arr[low]<=arr[mid]) // if the left half is sorted 
{

if(arr[low]<=k && k<=arr[mid]) // since we are doing binary search of k element so  if the elemetn lie between low and mid element then we will shink our domain 
{
    high=mid-1;  // eliminate the right half and now forward 
}

else
{
    low=mid+1;
}
}

// if the right half is sorted 
else
{  
if(arr[mid]<=k && k<=arr[high]) // if the right half is sorted
{
    low=mid+1;
}
else
{
    high=mid-1;
}



}

}
return -1;

}





int main()
{




    return 0;
}