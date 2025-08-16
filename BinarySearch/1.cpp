/*
lets write the code for binary seach here only 


find the mid element and then compare that element with  key and change the start and end point accordinly

if the search space is sorted and you have to find the element then go with binary search 


*/


#include<iostream>
using namespace std;

int binarySearch(int arr[],int size,int key)
{
    int start=0;
    int end=size-1;

    int mid=start+(end-start)/2;

    while(end>=start)
    {

if(arr[mid]==key)
return mid;

if(arr[mid]>key)
end=mid-1;

if(arr[mid]<key)
start=mid+1;


mid=start+(end-start)/2;

    }


}







int main()
{




    return 0;
}