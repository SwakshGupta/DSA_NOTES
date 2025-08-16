/*
here we will agian do the search in rotated sorted array but this time we also have duplicates in the array 

the code is similar to the previous question  . We will just add an extra condition to the code 



*/

#include<iostream>
using namespace std;

bool search(vector<int>&arr,int n,int k)
{

int low=0;
int high=n-1;

while(low<=high)
{

int mid=low+(high-low)/2;

if(arr[mid]==k)
return true;



if(arr[low]==arr[mid] && arr[mid]==arr[high]) // This is the extra condition added rest all the code is same as the previous 
{
    low++,high--;
    continue;
}

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
return false;

}







int main()
{




    return 0;
}