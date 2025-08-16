/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].


Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

here again in this question we will do the merge sort  so we will redimate copy the code for the merge sort 

*/

#include<iostream>
using namespace std;

void merge(vector<int>&arr,int low,int mid,int high)
{
vector<int>temp; 

int left=low;
int right=mid+1;

while(left<=mid && right<=high)
{

if(arr[left]<=arr[right])
{
    temp.push_back(arr[left++]);
}

if(arr[left]>=arr[right])
{
    temp.push_back(arr[right++]);
}
}

while(left<=mid)
{
    temp.push_back(arr[left++]);
}

while(right<=high)
{
    temp.push_back(arr[right++]);
}



for(int i=0; i<high; i++)
{
    arr[i]=temp[i-low];
}



}


int countPairs(vector<int>&arr,int low,int mid, int high)
{
int cnt=0;
int right=mid+1;
for(int i=low; i<=mid; i++)
{
    while(right<=high && arr[i]>2*arr[right]) right++;

    cnt+=(right-(mid+1));
}




}





void mergeSort(vector<int>&arr,int low,int high)
{
 int mid=(low+high)/2;

 if(high<=low)
 {
    return;
 }

mergeSort(arr,low,mid);
mergeSort(arr,mid+1,high);  
countPairs(arr,low,mid,high); // this is a extra function which we are creating here 


merge(arr,low,mid,high); 


}





int main()
{




    return 0;
}